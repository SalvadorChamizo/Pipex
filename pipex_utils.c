/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:14:44 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/19 14:36:36 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init_args(t_args *args, char **argv)
{
	int	i;

	i = 1;
	args->file1 = argv[i++];
	args->command1 = ft_split(argv[i++], ' ');
	args->cmd1 = ft_strjoin("/", args->command1[0]);
	args->command2 = ft_split(argv[i++], ' ');
	args->cmd2 = ft_strjoin("/", args->command2[0]);
	args->file2 = argv[i++];
}

void	open_infile(t_args *args)
{
	args->fd1 = open(args->file1, O_RDONLY);
	if (args->fd1 < 0)
	{
		perror("open");
		free_args(args);
		exit(EXIT_FAILURE);
	}
}

void	open_outfile(t_args *args)
{
	if (access(args->file2, F_OK) != 0)
	{
		args->fd2 = open(args->file2, O_WRONLY | O_CREAT, 0777);
		if (args->fd2 < 0)
		{
			perror("open");
			free_args(args);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		args->fd2 = open(args->file2, O_WRONLY);
		if (args->fd2 < 0)
		{
			perror("open");
			free_args(args);
			exit(EXIT_FAILURE);
		}
	}
}

void	child_process_cmd1(t_args *args, int pipefd[2], char **envp)
{
	if (dup2(args->fd1, STDIN_FILENO) == -1)
	{
		perror("dup2");
		free_args(args);
		exit(1);
	}
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		free_args(args);
		exit(1);
	}
	close(pipefd[0]);
	if (execve(args->cmd1_path, args->command1, envp) == -1)
	{
		perror("execve");
		free_args(args);
		exit(1);
	}
}

void	child_process_cmd2(t_args *args, int pipefd[2], char **envp)
{
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		free_args(args);
		exit(1);
	}
	if (dup2(args->fd2, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		free_args(args);
		exit(1);
	}
	write(2, "Llega\n", 6);
	close(pipefd[1]);
	if (execve(args->cmd2_path, args->command2, envp) == -1)
	{
		perror("execve");
		free_args(args);
		exit(1);
	}
}
