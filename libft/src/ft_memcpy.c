/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:28:54 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:43:31 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;

	char_dest = (unsigned char *) dst;
	char_src = (unsigned char *) src;
	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	while (n--)
	{
		*char_dest++ = *char_src++;
	}
	return (dst);
}

/*int	main(void)
{
	char	s[] = "abcdefghijklmnopqrstuvwxyz";
	char	d[0] = 'A';
	char	d2[0] = 'A';
	ft_memcpy(d, s, sizeof(s));
	memcpy(d2, s, sizeof(s));
	printf("%s\n", d);
	printf("%s\n", d2);
    return 0;
}*/

/* Copia información de un espacio de memoria a otro, 
sin tener en cuenta la superposición de memoria*/