/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory_bns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:13:02 by schamizo          #+#    #+#             */
/*   Updated: 2024/03/18 19:09:26 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bns.h"

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
		free(*args);
		*args = temp;
	}
	*args = NULL;
}

void	*free_args(t_args *args)
{
	int	i;

	ft_list_clear(&args->cmd);
	if (args->cmd_path)
		ft_list_clear(&args->cmd_path);
	while (args->command)
	{
		i = 0;
		while (args->command->cmd[i])
			i++;
		free_split(args->command->cmd, i);
		args->command = args->command->next;
	}
	return (NULL);
}
