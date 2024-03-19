/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:51:31 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:42:43 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
	return (0);
}

/*int main(void)
{
	char c;
	c = '7';
	
	if (ft_isdigit(c))
    {
        printf("El carácter es una letra del alfabeto\n");
    }
    else
    {
        printf("El carácter no es una letra del alfabeto\n");
    }

	printf("%c\n%d\n%d\n", c, isdigit(c), ft_isdigit(c));
}*/