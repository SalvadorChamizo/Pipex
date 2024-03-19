/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:02:07 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:43:52 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_print_nbr(int n)
{
	int		cont;
	char	c;

	cont = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		cont++;
	}
	if (n >= 10)
		cont += ft_print_nbr(n / 10);
	c = '0' + n % 10;
	write(1, &c, 1);
	cont++;
	return (cont);
}
