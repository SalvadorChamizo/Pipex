/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:38:49 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:43:35 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*char_dst;
	char	*char_src;

	char_dst = (char *)dst;
	char_src = (char *)src;
	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	if (char_dst <= char_src)
	{
		while (len--)
			*char_dst++ = *char_src++;
	}
	else if (dst > src)
	{
		char_dst = char_dst + len - 1;
		char_src += len - 1;
		while (len--)
			*char_dst-- = *char_src--;
	}
	return (dst);
}

/*int	main(void)
{
	char	dst[15];
	char	dst2[15];
	char	src[] = "Hola mundo";
	char	src2[] = "Hola mundo";

	ft_memmove(src+4, src+2, 11);
	memmove(dst2, src2+2, 11);
	printf("%s\n", dst);
	printf("%s\n", dst2);
}*/

/* Copia la información de un espacio de memoria a otro,
teniendo en cuenta la superposición de memoria. */