/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:04:38 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/25 13:03:22 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bns.h"

void	init_all_valgrind(t_args *args)
{
	args->cmd = NULL;
	args->cmd_path = NULL;
	args->command = NULL;
	args->first_cmd = NULL;
	args->first_path = NULL;
	args->first_command = NULL;
	args->file1 = NULL;
	args->file2 = NULL;
	args->limiter = NULL;
	args->cmd_nbr = 0;
	args->index = 0;
	args->fd1 = 0;
	args->fd2 = 0;
	args->heredoc_flag = 0;
}

void	init_here_doc(t_args *args, char **argv, int argc)
{
	int		i;
	t_cmd	*temp_cmd;
	t_list	*temp;
	t_list	*first;

	i = 2;
	temp = NULL;
	first = NULL;
	init_all_valgrind(args);
	args->heredoc_flag = 1;
	args->file1 = ".heredoc_tmp";
	args->limiter = argv[i++];
	while (i < argc - 1)
	{
		temp_cmd = ft_new_command(argv[i++]);
		ft_add_cmd_back(&args->command, temp_cmd);
		temp = ft_lstnew(ft_strjoin("/", temp_cmd->cmd[0]));
		if (!first)
			first = temp;
		ft_lstadd_back(&args->cmd, temp);
	}
	args->file2 = argv[i];
	args->cmd = first;
}

void	here_doc_pipex(t_args *args, char **argv, int argc)
{
	int		fd;
	char	*buffer;

	init_here_doc(args, argv, argc);
	fd = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		manage_error(args, "open");
	while (1)
	{
		ft_printf("heredoc> ");
		buffer = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(args->limiter, buffer, ft_strlen(args->limiter))
			&& ft_strlen(buffer) - 1 == ft_strlen(args->limiter))
			break ;
		write(fd, buffer, ft_strlen(buffer));
		free(buffer);
	}
	free(buffer);
	close(fd);
	args->fd1 = open(".heredoc_tmp", O_RDONLY);
	if (args->fd1 < 0)
	{
		unlink(".heredoc_tmp");
		manage_error(args, "open");
	}
}
