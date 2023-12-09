/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 03:02:25 by moer-ret          #+#    #+#             */
/*   Updated: 2023/12/09 20:42:58 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_new_line(char *tmp)
{
	int		i;
	char	*new_line;

	if (!tmp)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	new_line = malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		new_line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*get_new_line(char *tmp)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\0')
		return (NULL);
	if (tmp[i] == '\n')
		i++;
	new_line = malloc(sizeof(char) * (ft_strlen(tmp) - i + 1));
	if (!new_line)
		return (NULL);
	j = 0;
	while (tmp[i + j])
	{
		new_line[j] = tmp[i + j];
		j++;
	}
	new_line[j] = '\0';
	free (tmp);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			r_line;
	static char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	r_line = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(tmp, '\n') && r_line != 0)
	{
		r_line = read(fd, buffer, BUFFER_SIZE);
		if (r_line == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[r_line] = '\0';
		tmp = ft_strjoin(tmp, buffer);
	}
	free (buffer);
	buffer = read_new_line(tmp);
	tmp = get_new_line(tmp);
	return (buffer);
}
// int main()
// {
// 	int fd = open("test.txt", O_RDWR);
// 	char *str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("%s", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// }