/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:13:57 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:44:46 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*s2;
	char	*p;

	len = 0;
	while (s1[len])
		len++;
	s2 = malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	p = s2;
	while (*s1)
		*p++ = *s1++;
	*p = '\0';
	return (s2);
}

/* Aloca memoria para un nuevo string y copia el 
string dado en el nuevo, devolviendo el string creado*/