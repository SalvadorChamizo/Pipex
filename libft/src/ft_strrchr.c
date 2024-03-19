/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:31:35 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:45:20 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			last = (char *)s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (last);
}

/*int	main(void)
{
	char	s[] = "Hola muldo";
	printf("%p\n", ft_strrchr(s, 'o'));
	printf("%p\n", strrchr(s, 'o'));
}*/

/* Devuelve un puntero a la última
ocurrencia de un caracter en un string*/