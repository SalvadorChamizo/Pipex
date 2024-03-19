/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments_bns.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:55:38 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/19 15:36:55 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bns.h"

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
	ft_printf("%s\n", args->file1);
	if (access(args->file1, F_OK) != 0)
	{
		ft_printf("Infile not found\n");
		exit(0);
	}
	if (access(args->file1, R_OK) != 0)
	{
		ft_printf("Infile permissions denied\n");
		exit(5);
	}
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
	while (args->cmd)
	{
		temp = ft_lstnew(check_command(args->cmd->content, envp[i]));
		if (temp->content == NULL)
		{
			ft_printf("Command not found\n");
			free_args(args);
			exit(127);
		}
		ft_lstadd_back(&args->cmd_path, temp);
		args->cmd = args->cmd->next;
	}
	args->cmd = first;
	return (*args);
}
