/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:55:38 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/15 19:59:55 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*check_command(char *command, char **envp)
{
	char	*str;
	char	**split;
	int		i;
	int		j;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	str = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	split = ft_split(str, ':');
	free(str);
	j = 0;
	while (split[j] != NULL)
	{
		str = ft_strjoin(split[j], command);
		if (access(str, F_OK | X_OK) == 0)
			break ;
		free(str);
		str = NULL;
		j++;
	}
	while (split[j] != NULL)
		j++;
	free_split(split, j);
	return (str);
}

void	check_files(t_args args)
{
	if (access(args.file1, F_OK) != 0)
	{
		ft_printf("Infile not found\n");
		exit(0);
	}
	if (access(args.file1, R_OK) != 0)
	{
		ft_printf("Infile permissions denied\n");
		exit(5);
	}
}

t_args	check_args(t_args *args, char **envp)
{
	check_files(*args);
	args->cmd1_path = check_command(args->cmd1, envp);
	if (args->cmd1_path == NULL)
	{
		ft_printf("Command not found\n");
		free_args(args);
		exit(127);
	}
	args->cmd2_path = check_command(args->cmd2, envp);
	if (args->cmd2_path == NULL)
	{
		ft_printf("Command not found\n");
		free(args->cmd2_path);
		exit(127);
	}
	return (*args);
}
