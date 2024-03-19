/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:20:28 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:42:34 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
	return (0);
}

/*int	main(void)
{
	char c;
	c = 'A';

	if (ft_isalnum(c))
    {
        printf("El carácter es una letra del alfabeto\n");
    }
    else
    {
        printf("El carácter no es una letra del alfabeto\n");
    }

	printf("%c\n%d\n%d\n", c, isalnum(c), ft_isalnum(c));
}*/