/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:20:58 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:44:58 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	c;
	unsigned int	k;

	i = ft_strlen(dest);
	c = ft_strlen(src);
	k = 0;
	if (i >= size)
		return (size + c);
	while (src[k] != '\0' && (k < (size - i - 1)))
	{
		dest[i + k] = src[k];
		k++;
	}
	dest[i + k] = '\0';
	return (i + c);
}
/*
int	main(void)
{
	char	dest[25] = "Oye,";
	char	src[20] = " hola pepe que pasa";
	char	dest2[25] = "Oye,";
	unsigned int	resultado;
	unsigned int	resultado2;

	resultado = ft_strlcat(dest, src, 25);
	printf("%s\n%d\n", dest, resultado);
	resultado2 = strlcat(dest2, src, 25);
	printf("%s\n%d\n", dest2, resultado2);
	return (0);
}*/

/* Concatena dos strings, asegurándose de que siempre
haya espacio para el nulo al final.
Devuelve el número de caracteres que tendría el string completo */