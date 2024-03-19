/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:07:32 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:43:24 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*char_s;
	size_t			len;

	char_s = (unsigned char *)s;
	len = 0;
	while (len < n)
	{
		if (char_s[len] == (unsigned char)c)
			return ((void *)&char_s[len]);
		len++;
	}
	return (NULL);
}

/*int	main(void)
{
	char s[] = "Hola mundo";
	char *d;
	char *d2;
	d = ft_memchr(s, (-108), 10);
	d2 = memchr(s, (-108), 10);
	printf("%s\n", d);
	printf("%s\n", d2);
}*/

/* Busca un byte específico en un espacio de memoria. 
Devuelve un void * al byte si lo encuentra */