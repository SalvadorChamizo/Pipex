/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:14:44 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/19 16:25:02 by schamizo         ###   ########.fr       */
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
	args->file1 = argv[i++];
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

/*void	init_args(t_args *args, char **argv, int argc)
{
	int	i;
	t_cmd	*temp_cmd;
	t_list	*temp;
	char	*str;

	i = 1;
	temp = NULL;
	args->file1 = argv[i++];
	while (i < argc - 1)
	{
		temp_cmd = ft_new_command(argv[i++]);
		ft_add_cmd_back(&args->command, temp_cmd);
		ft_printf("En i = %d\n%s\n", i, temp_cmd->cmd[0]);
		str = ft_strjoin("/", temp_cmd->cmd[0]);
		ft_printf("Aquí: %s\n", str);
		temp = ft_lstnew(str);
		ft_printf("Content: %s\n", temp->content);
		ft_stack_add_back(&args->cmd, temp);
		ft_printf("Después de stack back%s\n", args->cmd->content);
	}
	args->file2 = argv[i];
	ft_printf("%s\n", args->cmd->content);
	args->cmd = args->cmd->next;
	ft_printf("%s\n", args->cmd->content);
}*/

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
	close(args->fd1);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		free_args(args);
		exit(1);
	}
	close(pipefd[1]);
	close(pipefd[0]);
	if (execve(args->cmd_path->content, args->command->cmd, envp) == -1)
	{
		perror("execve");
		free_args(args);
		exit(1);
	}
}

void	middle_process_cmd(t_args *args, int pipefd[2], char **envp)
{
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		free_args(args);
		exit(1);
	}
	close(pipefd[0]);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		free_args(args);
		exit(1);
	}
	close(pipefd[1]);
	if (execve(args->cmd_path->content, args->command->cmd, envp) == -1)
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
	close(pipefd[0]);
	if (dup2(args->fd2, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		free_args(args);
		exit(1);
	}
	close(pipefd[1]);
	if (execve(args->cmd_path->content, args->command->cmd, envp) == -1)
	{
		perror("execve");
		free_args(args);
		exit(1);
	}
}
