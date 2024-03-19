/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schamizo <schamizo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:02:07 by schamizo          #+#    #+#             */
/*   Updated: 2024/02/21 19:45:57 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*get_lines(char *str)
{
	int		i;
	char	*line;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*keep_lines(char *str)
{
	int		n;
	int		i;
	char	*next_line;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		safe_free(str);
		return (NULL);
	}
	n = ft_strlen(str);
	next_line = ft_calloc(n - i + 1, sizeof(char));
	if (next_line == NULL)
		return (NULL);
	n = 0;
	i++;
	while (str[i] != '\0')
		next_line[n++] = str[i++];
	next_line[n] = '\0';
	safe_free(str);
	return (next_line);
}

int	find_line(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || ft_strcmp(str, "") == 0)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_lines(int fd, char *buffer, char *str, char *temp)
{
	int		bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		temp = str;
		if (temp == NULL)
		{
			temp = malloc(sizeof(char));
			if (temp == NULL)
				return (NULL);
			temp[0] = '\0';
		}
		str = ft_strjoin(temp, buffer);
		safe_free(temp);
		if (find_line(str) == 1 || bytes_read == 0)
			break ;
	}
	safe_free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[2048];
	char		*buffer;
	char		*new_line;
	char		*temp;

	if (read(fd, 0, 0) == -1)
	{
		safe_free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	if (fd <= -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	temp = NULL;
	str[fd] = read_lines(fd, buffer, str[fd], temp);
	if (str[fd] == NULL)
		return (safe_free(buffer), NULL);
	new_line = get_lines(str[fd]);
	str[fd] = keep_lines(str[fd]);
	return (new_line);
}
