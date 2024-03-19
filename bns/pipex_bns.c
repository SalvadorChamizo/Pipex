/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:22:04 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/19 18:02:04 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bns.h"

void	ft_add_cmd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*last;

	last = *lst;
	if (!last)
		*lst = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

t_cmd	*ft_new_command(char *content)
{
	t_cmd	*new;

	new = NULL;
	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	if (new)
	{
		new->cmd = ft_split(content, ' ');
		new->next = NULL;
	}
	return (new);
}

void	ft_pipex(t_args	*args, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid1 = fork();
	if (pid1 == -1)
		exit(1);
	if (pid1 == 0)
		child_process_cmd1(args, pipefd, envp);
	pid2 = fork();
	if (pid2 == -1)
		exit(1);
	if (pid2 == 0)
		child_process_cmd2(args, pipefd, envp);
	else
	{
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
		return ;
	}
}

void	ft_pipex_bns(t_args	*args, int argc, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2 = -1;
	pid_t	pid3 = -1;
	int		i;

	i = 2;
	if (strncmp(args->file1, ".heredoc_tmp", ft_strlen(args->file1)) == 0)
		i = 3;
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	ft_printf("Este es 1: %s\n", args->cmd_path->content);
	pid1 = fork();
	if (pid1 == -1)
		exit(1);
	if (pid1 == 0)
		child_process_cmd1(args, pipefd, envp);
	else
		waitpid(pid1, NULL, 0);
	while (i < argc - 3)
	{
		args->command = args->command->next;
		args->cmd = args->cmd->next;
		args->cmd_path = args->cmd_path->next;
		ft_printf("Este es 2: %s\n", args->cmd_path->content);
		pid2 = fork();
		if (pid2 == 0)
			middle_process_cmd(args, pipefd, envp);
		else
			waitpid(pid2, NULL, 0);
		i++;
	}
	args->command = args->command->next;
	args->cmd = args->cmd->next;
	args->cmd_path = args->cmd_path->next;
	pid3 = fork();
	if (pid3 == -1)
		exit(1);
	if (pid3 == 0)
	{
		ft_printf("Este es 3: %s\n", args->cmd_path->content);
		child_process_cmd2(args, pipefd, envp);
	}
	else
	{
		/*waitpid(pid1, NULL, 0);*/
		ft_printf("1\n");
	if (pid3 != -1)
		waitpid(pid3, NULL, 0);
		ft_printf("2\n");
		/*wait(NULL);*/
		ft_printf("3\n");
		return ;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_args	*args;

	if (argc >= 5)
	{
		args = malloc(sizeof(t_args));
		if (ft_strcmp(argv[1], "here_doc") == 0)
		{
			here_doc_pipex(args, argv, argc);
			*args = check_args(args, envp);
			open_outfile(args);
		}
		else
		{
			init_args(args, argv, argc);
			*args = check_args(args, envp);
			open_infile(args);
			open_outfile(args);
		}
		if (argc == 5)
			ft_pipex(args, envp);
		else
			ft_pipex_bns(args, argc, envp);
		unlink(".heredoc_tmp");
	}
	else
	{
		ft_printf("Error: Few arguments passed\n");
		exit(1);
	}
	return (0);
}
