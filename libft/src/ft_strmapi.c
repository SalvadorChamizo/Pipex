/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:39:07 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:45:08 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*s2;

	i = 0;
	len = ft_strlen(s);
	s2 = malloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	while (len--)
	{
		s2[i] = (*f)(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/* Aloca memoria para un nuevo string y copia
el string pasado, aplicando una función a cada caracter */