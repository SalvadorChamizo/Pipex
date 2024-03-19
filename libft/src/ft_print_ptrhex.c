/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptrhex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:05:23 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:43:58 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_print_ptrhex(unsigned long int n)
{
	int	cont;

	cont = 0;
	if (n >= 16)
	{
		cont += ft_print_ptrhex(n / 16);
		cont += ft_print_ptrhex(n % 16);
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
