/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:07:23 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:43:38 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	if (len == 0)
		return (b);
	while (len > 0)
	{
		*p = (unsigned char) c;
		p++;
		len--;
	}
	return (b);
}

/*int	 main(void)
{
	char	buffer[10];
	char	buffer2[10];
	ft_memset(buffer, 'a', sizeof(buffer));
	memset(buffer2, 'a', sizeof(buffer2));
	printf("Esta es buffer: %s\n", buffer);
	printf("Esta es buffer2: %s\n", buffer2);
}*/