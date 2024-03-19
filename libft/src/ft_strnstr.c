/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:55:20 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:45:15 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while ((haystack[i + c] == needle[c]
				|| haystack[i] != '\0') && i + c <= len)
		{
			if (needle[c] == '\0')
				return ((char *)&haystack[i]);
			if (haystack[i + c] != needle[c])
				break ;
			c++;
		}
		c = 0;
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	s1[] = "Hola mundo, que tal estas que pasa";
	char	s2[] = "que";
	char	*resultado;
	char	*resultado2;

	resultado = ft_strnstr("abcdefgh", "abc", 2);
	resultado2 = strnstr("abcdefgh", "abc", 2);
	printf("%s\n", resultado);
	printf("%s\n", resultado2);
}*/

/* Encuentra una string dentro de otra */