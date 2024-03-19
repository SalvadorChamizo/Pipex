/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:31:59 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:44:33 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

/*int	main(void)
{
	char c;
	char	*s = "Hola mundo";
	char	*p;
	char	*q;
	c = 'l';
	p = strchr("teste", 'e');
	q = ft_strchr("teste", 'e');
	printf("%p\n", p);
	printf("%p\n", q);
	return (0);
}*/