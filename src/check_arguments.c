/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:55:38 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/25 19:10:40 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*check_command(char *command, char *envp)
{
	char	*str;
	char	**split;
	int		i;

	i = 0;
	str = ft_substr(envp, 5, ft_strlen(envp));
	split = ft_split(str, ':');
	free(str);
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

t_args	check_args(t_args *args, char **envp)
{
	int	i;

	i = 0;
	check_files(args);
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	args->cmd1_path = check_command(args->cmd1, envp[i]);
	if (args->cmd1_path == NULL)
	{
		ft_printf("Command not found\n");
		free_args(args);
		exit(127);
	}
	args->cmd2_path = check_command(args->cmd2, envp[i]);
	if (args->cmd2_path == NULL)
	{
		ft_printf("Command not found\n");
		free_args(args);
		exit(127);
	}
	return (*args);
}
