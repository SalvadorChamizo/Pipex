/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:33:24 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:42:49 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_intlen(int n)
{
	int	count;

	count = 1;
	if (n < 0 && n != -2147483648)
	{
		count++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*each_number(char *s, int n, int cont)
{
	int	negative;
	int	n2;

	negative = 0;
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
		negative = 1;
		cont--;
	}
	while (cont--)
	{
		n2 = n % 10;
		s[cont + negative] = '0' + n2;
		n = n / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		cont;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = ft_calloc(ft_intlen(n) + 1, sizeof(char));
	if (s == NULL)
		return (NULL);
	cont = ft_intlen(n);
	s = each_number(s, n, cont);
	s[ft_intlen(n)] = '\0';
	return (s);
}

/*int	main(void)
{
	char	*s;

	s = ft_itoa(-2453433);
	printf("%s\n", s);
}*/

/* ft_itoa convierte un entero a un string 
de números, asignando memoria dinámica
según el número de dígitos y su signo*/