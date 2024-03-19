/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:46:39 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:44:09 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	access_format(va_list args, char c)
{
	int	cont;

	cont = 0;
	if (c == 'c')
		cont += ft_print_char(va_arg(args, int));
	else if (c == 's')
		cont += ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		cont += ft_print_ptr((unsigned long int)va_arg(args, void *));
	else if (c == 'd')
		cont += ft_print_nbr(va_arg(args, int));
	else if (c == 'i')
		cont += ft_print_nbr(va_arg(args, int));
	else if (c == 'u')
		cont += ft_print_unsig(va_arg(args, unsigned int));
	else if (c == 'x')
		cont += ft_print_hex(va_arg(args, unsigned int));
	else if (c == 'X')
		cont += ft_print_hexup(va_arg(args, unsigned int));
	else if (c == '%')
		cont += ft_print_char('%');
	return (cont);
}

int	check_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		cont;

	va_start(args, str);
	if (write(1, "", 0) == -1)
		return (-1);
	i = 0;
	cont = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && check_format(str[i + 1]))
		{
			cont += access_format(args, str[i + 1]);
			i++;
		}
		else
			cont += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (cont);
}

/*int main(void)
{
	int n;

	n = 42;
	printf("La mía devuelve: %d\n", ft_printf("Imprime %c\n", 'h'));
	printf("La original devuelve: %d\n", printf("Imprime %c\n", 'h'));
	printf("La mía devuelve: %d\n", ft_printf("Imprime %d\n", 125));
	printf("La original devuelve: %d\n", printf("Imprime %d\n", 125));
	printf("La mía devuelve: %d\n", ft_printf("Imprime %p\n", &n));
	printf("La original devuelve: %d\n", printf("Imprime %p\n", &n));
	printf("La mía devuelve: %d\n", ft_printf("Imprime %s\n", "Hola mundo"));
	printf("La original devuelve: %d\n", printf("Imprime %s\n", "Hola mundo"));
}*/
