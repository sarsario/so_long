/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:06:12 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/20 21:16:01 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	try_read(int fd, char **line)
{
	char	*buffer;
	char	*temp;
	int		i;

	buffer = (char *)malloc(sizeof(char) * 2);
	if (!buffer)
		return (-1);
	ft_bzero(buffer, 2);
	i = read(fd, buffer, 1);
	while (i > 0)
	{
		if (buffer[0] == '\n')
			break ;
		temp = *line;
		*line = ft_strjoin(*line, buffer);
		free(temp);
		i = read(fd, buffer, 1);
	}
	free(buffer);
	return (i);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		i;

	line = (char *)malloc(sizeof(char) * 2);
	if (!line)
		return (NULL);
	ft_bzero(line, 2);
	i = try_read(fd, &line);
	if (i == -1)
		free(line);
	if (i == -1)
		return (NULL);
	return (line);
}
