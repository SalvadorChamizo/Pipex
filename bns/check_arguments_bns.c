/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments_bns.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:55:38 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/25 19:21:53 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bns.h"

void	init_args(t_args *args, char **argv, int argc)
{
	int		i;
	t_cmd	*temp_cmd;
	t_list	*temp;
	t_list	*first;

	i = 1;
	temp = NULL;
	first = NULL;
	init_all_valgrind(args);
	args->file1 = argv[i++];
	while (i < argc - 1)
	{
		temp_cmd = ft_new_command(argv[i++]);
		ft_add_cmd_back(&args->command, temp_cmd);
		temp = ft_lstnew(ft_strjoin("/", temp_cmd->cmd[0]));
		if (!first)
			first = temp;
		ft_lstadd_back(&args->cmd, temp);
		args->cmd_nbr++;
	}
	args->file2 = argv[i];
	args->cmd = first;
}

char	*check_command(char *command, char *envp)
{
	char	*str;
	char	**split;
	int		i;

	str = ft_substr(envp, 5, ft_strlen(envp));
	split = ft_split(str, ':');
	free(str);
	i = 0;
	while (split[i] != NULL)
	{
		str = ft_strjoin(split[i], command);
		if (access(str, F_OK | X_OK) == 0)
			break ;
		free(str);
		str = NULL;
		i++;
	}
	while (split[i] != NULL)
		i++;
	free_split(split, i);
	return (str);
}

void	check_files(t_args *args)
{
	if (access(args->file1, F_OK) != 0)
	{
		ft_printf("Infile not found\n");
		free_args(args);
		exit(1);
	}
	if (access(args->file1, R_OK) != 0)
	{
		ft_printf("Infile permissions denied\n");
		free_args(args);
		exit(5);
	}
}

void	aux_error_args(t_args *args, t_list *temp)
{
	if (args->heredoc_flag == 1)
		unlink(".heredoc_tmp");
	free(temp);
	ft_printf("Command not found\n");
	free_args(args);
	exit(127);
}

t_args	check_args(t_args *args, char **envp)
{
	t_list	*temp;
	t_list	*first;
	int		i;

	temp = args->cmd_path;
	first = args->cmd;
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	check_files(args);
	while (first)
	{
		temp = ft_lstnew(check_command(first->content, envp[i]));
		if (temp->content == NULL)
			aux_error_args(args, temp);
		ft_lstadd_back(&args->cmd_path, temp);
		first = first->next;
	}
	return (*args);
}
