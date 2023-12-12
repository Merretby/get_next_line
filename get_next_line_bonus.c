/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:44:49 by moer-ret          #+#    #+#             */
/*   Updated: 2023/12/12 18:12:20 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(char *tmp)
{
	int		i;
	char	*line;

	if (!tmp || !tmp[0])
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_line(char *tmp, int i)
{
	int		j;
	char	*line;

	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\0')
	{
		free(tmp);
		return (NULL);
	}
	if (tmp[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (ft_strlen(tmp) - i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (tmp[i + j])
	{
		line[j] = tmp[i + j];
		j++;
	}
	line[j] = '\0';
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	int			r_line;
	char		*buffer;
	static char	*tmp[MAX];

	if (fd < 0 || fd > MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE >= SIZE_MAX)
		return (NULL);
	r_line = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(tmp[fd], '\n') && r_line != 0)
	{
		r_line = read(fd, buffer, BUFFER_SIZE);
		if (r_line == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[r_line] = '\0';
		tmp[fd] = ft_strjoin(tmp[fd], buffer);
	}
	free(buffer);
	buffer = read_line(tmp[fd]);
	tmp[fd] = get_line(tmp[fd], 0);
	return (buffer);
}
