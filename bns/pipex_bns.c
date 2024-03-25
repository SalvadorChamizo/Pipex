/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:22:04 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/25 19:57:47 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bns.h"

void	ft_pipex(t_args	*args, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		manage_error(args, "pipe");
	if (dup2(args->fd1, STDIN_FILENO) == -1)
		manage_error(args, "dup2");
	child_process_cmd(args, pipefd, envp);
	if (dup2(args->fd2, STDOUT_FILENO) == -1)
		manage_error(args, "dup2");
	pid = fork();
	if (pid == -1)
		manage_error(args, "fork");
	if (pid == 0)
	{
		if (execve(args->cmd_path->content, args->command->cmd, envp) == -1)
			manage_error(args, "execve");
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}

void	ft_pipex_bns_end(t_args *args, char **envp)
{
	pid_t	pid;

	if (dup2(args->fd2, STDOUT_FILENO) == -1)
		manage_error(args, "dup2");
	pid = fork();
	if (pid == -1)
		manage_error(args, "fork");
	if (pid == 0)
	{
		if (execve(args->cmd_path->content, args->command->cmd, envp) == -1)
			manage_error(args, "execve");
	}
	else
	{
		waitpid(pid, NULL, 0);
		args->cmd = args->first_cmd;
		args->cmd_path = args->first_path;
		args->command = args->first_command;
	}
}

void	ft_pipex_bns(t_args *args, int argc, char **envp)
{
	int		i;

	i = 2;
	if (dup2(args->fd1, STDIN_FILENO) == -1)
		manage_error(args, "dup2");
	while (i < argc - 2)
	{
		child_manage(args, envp);
		args->index++;
		if (args->command->next)
		{
			args->command = args->command->next;
			args->cmd = args->cmd->next;
			args->cmd_path = args->cmd_path->next;
		}
		i++;
	}
	ft_pipex_bns_end(args, envp);
}

t_args	*start_pipex(t_args *args, char **argv, int argc, char **envp)
{
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
	args->first_cmd = args->cmd;
	args->first_path = args->cmd_path;
	args->first_command = args->command;
	return (args);
}

int	main(int argc, char **argv, char **envp)
{
	t_args	*args;

	if (argc >= 5)
	{
		args = malloc(sizeof(t_args));
		if (!args)
			return (1);
		args = start_pipex(args, argv, argc, envp);
		if (argc == 5)
			ft_pipex(args, envp);
		else
			ft_pipex_bns(args, argc, envp);
		if (ft_strcmp(argv[1], "here_doc") == 0)
			unlink(".heredoc_tmp");
		free_args(args);
	}
	else
	{
		ft_printf("Error: Few arguments passed\n");
		exit(1);
	}
	return (0);
}
