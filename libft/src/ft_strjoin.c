/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:42:57 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:44:54 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	char	*p;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = malloc(len1 + len2 + 1);
	if (s3 == NULL)
		return (NULL);
	p = s3;
	while (len1--)
		*p++ = *s1++;
	while (len2--)
		*p++ = *s2++;
	*p = '\0';
	return (s3);
}

/*int	main(void)
{
	char s1[] = "Hola mundo ";
	char s2[] = "que tal?";
	char *s3;

	s3 = ft_strjoin(s1, s2);
	printf("%s\n", s3);
	return (0);
}*/

/* Concatena dos strings, alocando memoria suficiente para ello */