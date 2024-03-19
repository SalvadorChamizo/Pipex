/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:38:18 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:42:40 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
	return (0);
}

/*int	main(void)
{
	char c;
	c = '}';

	if (isascii(c))
    {
        printf("El carácter es una letra del alfabeto\n");
    }
    else
    {
        printf("El carácter no es una letra del alfabeto\n");
    }

	printf("%c\n%d\n%d\n", c, isascii(c), ft_isascii(c));
}*/