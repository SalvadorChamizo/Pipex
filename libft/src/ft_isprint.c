/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:50:54 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:42:46 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isprint(int c)
{
	if ((c >= ' ' && c <= '~'))
		return (1);
	else
		return (0);
	return (0);
}

/*int main(void)
{
	char c;
	c = 126;

	if (ft_isprint(c))
    {
        printf("El carácter es una letra del alfabeto\n");
    }
    else
    {
        printf("El carácter no es una letra del alfabeto\n");
    }

	printf("%c\n%d\n%d\n", c, isprint(c), ft_isprint(c));
}*/