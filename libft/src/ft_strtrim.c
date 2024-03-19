/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:57:53 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:45:24 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	check_char(char const *s1, char ch)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == ch)
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len1;
	size_t	i;

	i = 0;
	len1 = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (check_char(set, s1[i]))
		i++;
	while (check_char(set, s1[len1]))
		len1--;
	return (ft_substr(s1, i, len1 - (i - 1)));
}

/*int main(void)
{
	char s[] = "aaababbaMy name is Simonbababbb";
	char s2[] = "ab";
	char *s3;

	s3 = ft_strtrim(s, s2);
	printf("%s\n", s3);
	return (0);
}*/

/* Elimina los caracteres dados, al principio y 
al final de un string, y aloca memoria para el string resultante */