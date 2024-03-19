/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:14:50 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:45:02 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < len - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/*int	main(void)
{
	char	dest[] = "Hola quefdhbisbduabdusb";
	char	src[] = "tu, mundo";
	char	dest2[] = "Hola quefdhbisbduabdusb";
	int	i;
	int j;

	i = ft_strlcpy(dest, src, 30);
	j = strlcpy(dest2, src, 30);
	printf("%d\n%d\n%s\n%s\n", i, j, dest, dest2);
}
*/