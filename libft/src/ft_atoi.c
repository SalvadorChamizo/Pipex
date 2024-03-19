/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:44:07 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:42:18 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !(str[i] == '+' || str[i] == '-'))
	{
		if ((str[i] == ' ') || (str[i] >= '\t' && str[i] <= '\r'))
			i++;
		else
			break ;
	}
	return (i);
}

static int	ft_negative(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

long int	ft_atoi(const char *str)
{
	int			i;
	int			num1;
	long int	num2;

	num2 = 0;
	i = ft_spaces(str);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			break ;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			num1 = str[i] - '0';
			num2 = num2 * 10 + num1;
		}
		i++;
	}
	if (ft_negative(str))
		num2 = -num2;
	return (num2);
}

/*int main(void)
{
	char	str[] = "  -2147483648";
	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
}*/

/* ft_atoi convierte un string de números en un int. Se salta los espacios según
y determina si el número es negativo o no*/