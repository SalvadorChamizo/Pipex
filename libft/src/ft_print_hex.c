/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:24:24 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:43:45 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_print_hex(unsigned int n)
{
	int	cont;

	cont = 0;
	if (n >= 16)
	{
		cont += ft_print_hex(n / 16);
		cont += ft_print_hex(n % 16);
	}
	else
	{
		if (n < 10)
		{
			ft_print_char('0' + n);
			cont++;
		}
		else if (n >= 10)
		{
			ft_print_char((n - 10) + 'a');
			cont++;
		}
	}
	return (cont);
}
