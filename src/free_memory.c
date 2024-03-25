/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:13:02 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/25 19:08:51 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	manage_error(t_args *args, char *error)
{
	perror(error);
	free_args(args);
	exit(EXIT_FAILURE);
}

void	*free_split(char **str, int cont)
{
	int	i;

	i = 0;
	while (i < cont)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void	free_command(t_args *args)
{
	int	i;

	i = 0;
	if (args->command1 != NULL)
	{
		while (args->command1[i])
			i++;
		free_split(args->command1, i);
	}
	i = 0;
	if (args->command2 != NULL)
	{
		while (args->command2[i])
			i++;
		free_split(args->command2, i);
	}
}

void	*free_args(t_args *args)
{
	if (args->cmd1 != NULL)
		free(args->cmd1);
	if (args->cmd2 != NULL)
		free(args->cmd2);
	if (args->cmd1_path != NULL)
		free(args->cmd1_path);
	if (args->cmd2_path != NULL)
		free(args->cmd2_path);
	free_command(args);
	if (args != NULL)
		free(args);
	return (NULL);
}
