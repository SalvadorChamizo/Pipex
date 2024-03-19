/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:01:14 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:42:29 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, count * size);
	return (p);
}

/*int	main(void)
{
	char *s;
	s = ft_calloc(10, sizeof(char));
	printf("%s\n", s);
	free(s);
}*/

/* Asigna memoria dinámica con Malloc y la inicializa con nulos,
devuelve un void * al primer espacio de memoria*/