/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:48:56 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:44:30 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	count_words(const char *s, char c)
{
	int	cont;
	int	check;

	cont = 0;
	check = 0;
	while (*s)
	{
		if (*s != c && check == 0)
		{
			cont++;
			check = 1;
		}
		else if (*s == c)
			check = 0;
		s++;
	}
	return (cont);
}

static void	*free_all(char **str, int cont)
{
	int	i;

	i = 0;
	while (i < cont)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**fill_split(char	**str, char const *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	j;
	int		start;

	len = ft_strlen(s);
	i = 0;
	j = 0;
	start = -1;
	while (i <= len)
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == len) && start >= 0)
		{
			str[j] = ft_substr(s, start, i - start);
			if (str[j] == NULL)
				return (free_all(str, j));
			j++;
			start = -1;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	size_t	len;
	size_t	i;
	size_t	j;
	int		start;

	len = ft_strlen(s);
	i = 0;
	j = 0;
	start = -1;
	str = (char **) malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (str == NULL)
		return (NULL);
	str = fill_split(str, s, c);
	return (str);
}

/*int main(void)
{
	char *s = "lorem ipsum dolor sit amet, 
	consectetur adipiscing elit. Sed non risus. Suspendisse";
	char **str;
	char c = ' ';
	int i = 0;

	str = ft_split(s, c);
	while (i < count_words(s, c))
	{
		printf("%s\n", str[i]);
		i++;
	}
	free_all(str, count_words(s, c));
	return (0);
}*/

/* Divide un string, separado por un caracter dado, en substrings, 
y aloca memoria para un array y para cada substring. 
Si algo falla, libera la memoria de todos los que ha creado hasta ahora */