/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:39:48 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:42:52 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if (!last)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

/*int	main(void)
{
	t_list	*list;
	t_list	*element1;
	t_list	*element2;

	list = NULL;
	element1 = ft_lstnew("Hello");
	element2 = ft_lstnew("World");

	ft_lstadd_back(&list, element1);
	ft_lstadd_back(&list, element2);
	while (list)
	{
		printf("%s ", (char *)list->content);
		list = list->next;
	}
	printf("\n");

	return (0);
}*/

/* Añade un elemento nuevo al final de una lista enlazada*/