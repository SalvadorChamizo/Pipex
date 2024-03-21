/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:13:02 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/21 17:25:11 by schamizo         ###   ########.fr       */
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

void	*free_args(t_args *args)
{
	int	i;

	i = 0;
	free(args->cmd1);
	free(args->cmd2);
	if (args->cmd1_path != NULL)
		free(args->cmd1_path);
	if (args->cmd2_path != NULL)
		free(args->cmd2_path);
	while (args->command1[i])
		i++;
	free_split(args->command1, i);
	i = 0;
	while (args->command2[i])
		i++;
	free_split(args->command2, i);
	free(args);
	return (NULL);
}
