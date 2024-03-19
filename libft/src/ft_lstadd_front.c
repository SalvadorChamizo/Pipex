/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:13:09 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:42:56 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new && lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*int main(void)
{
	t_list	*list;
	t_list	*element1;
	t_list	*element2;

	list = NULL;
	element1 = ft_lstnew("Hello");
	element2 = ft_lstnew("World");

	ft_lstadd_front(&list, element2);
	ft_lstadd_front(&list, element1);

	while (list)
	{
		printf("%s ", (char *)list->content);
		list = list->next;
	}
	printf("\n");
	return (0);
}*/

/* Añade un elemento nuevo al principio de una lista enlazada */