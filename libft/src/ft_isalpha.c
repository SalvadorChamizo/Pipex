/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:49:52 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:42:37 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
	return (0);
}

/*int main(void)
{
    char c;
    c = 'z';

	if (ft_isalpha(c))
    {
        printf("El carácter es una letra del alfabeto\n");
    }
    else
    {
        printf("El carácter no es una letra del alfabeto\n");
    }

    printf("%c\n%d\n%d", c, isalpha(c), ft_isalpha(c));
}*/