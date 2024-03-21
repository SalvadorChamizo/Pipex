/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bns.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:22:21 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/21 15:09:31 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BNS_H
# define PIPEX_BNS_H

# include "../libft/include/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_cmd
{
	char			**cmd;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_args
{
	t_list	*cmd;
	t_list	*cmd_path;
	t_cmd	*command;
	t_list	*first_cmd;
	t_list	*first_path;
	t_cmd	*first_command;
	char	*limiter;
	char	*file1;
	char	*file2;
	int		fd1;
	int		fd2;
	int		cmd_nbr;
	int		index;
}	t_args;

/* Check_arguments */

void	init_all_valgrind(t_args *args);
void	init_args(t_args *args, char **argv, int argc);
char	*check_command(char *command, char *envp);
void	check_files(t_args *args);
t_args	check_args(t_args *args, char **envp);

/* Free_memory */

void	manage_error(t_args *args, char *error);
void	*free_split(char **str, int cont);
void	*free_args(t_args *args);

/* Here_doc_func */

void	init_here_doc(t_args *args, char **argv, int argc);
void	here_doc_pipex(t_args *args, char **argv, int argc);

/* Open_fd_bns */

void	open_infile(t_args *args);
void	open_outfile(t_args *args);

/* Pipex_utils */

void	child_manage(t_args *args, char **envp);
void	child_process_cmd1(t_args *args, int pipefd[2], char **envp);
void	child_process_cmd2(t_args *args, int pipefd[2], char **envp);
void	ft_add_cmd_back(t_cmd **lst, t_cmd *new);
t_cmd	*ft_new_command(char *content);

#endif