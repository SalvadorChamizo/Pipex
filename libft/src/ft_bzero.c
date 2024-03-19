/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:04:40 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:42:24 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

/*int	main(void)
{
	char	s[10] = "Hola mundo";
	char	s2[10] = "Hola mundo";
	ft_bzero(s, 3);
	bzero(s2, 3);

	printf("%s\n", s);
	printf("%s\n", s2);
}*/

/* ft_bzero rellena un espacio de memoria con nulos*/