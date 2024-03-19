/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:22:04 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/19 14:37:50 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_pipex(t_args	*args, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		child_process_cmd1(args, pipefd, envp);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		child_process_cmd2(args, pipefd, envp);
	else
	{
		ft_printf("Aquí llega\n");
		wait(NULL);
		ft_printf("Aquí también\n");
		ft_printf("Aquí no\n");
		return ;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_args	args;

	if (argc == 5)
	{
		init_args(&args, argv);
		args = check_args(&args, envp);
		open_infile(&args);
		open_outfile(&args);
		ft_pipex(&args, envp);
		free_args(&args);
	}
	else
	{
		ft_printf("Error: Few arguments passed\n");
		exit(1);
	}
	return (0);
}
