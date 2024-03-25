/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory_bns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:13:02 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/25 12:41:56 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bns.h"

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

void	ft_list_clear(t_list **args)
{
	t_list	*temp;

	if (!args)
		return ;
	while (*args)
	{
		temp = (*args)->next;
		free((*args)->content);
		free(*args);
		*args = temp;
	}
	*args = NULL;
}

void	free_path(t_args *args)
{
	t_list	*temp_path;

	temp_path = args->cmd_path;
	while (args->cmd_path)
	{
		free(args->cmd_path->content);
		args->cmd_path = args->cmd_path->next;
	}
	args->cmd_path = temp_path;
	ft_list_clear(&args->cmd_path);
}

void	*free_args(t_args *args)
{
	int		i;
	t_cmd	*temp;

	ft_list_clear(&args->cmd);
	if (args->cmd_path)
		ft_list_clear(&args->cmd_path);
	while (args->command)
	{
		i = 0;
		while (args->command->cmd[i])
			i++;
		free_split(args->command->cmd, i);
		temp = args->command->next;
		free(args->command);
		args->command = temp;
	}
	free(args);
	return (NULL);
}
