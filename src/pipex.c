/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:22:04 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/25 19:43:22 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
		if (execve(args->cmd2_path, args->command2, envp) == -1)
			manage_error(args, "execve");
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_args	*args;

	if (argc == 5)
	{
		args = malloc(sizeof(t_args));
		if (!args)
			manage_error(args, "malloc");
		init_args(args, argv);
		*args = check_args(args, envp);
		open_infile(args);
		open_outfile(args);
		ft_pipex(args, envp);
		free_args(args);
	}
	else
	{
		ft_printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
