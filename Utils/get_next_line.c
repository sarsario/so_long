/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:06:12 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/23 19:55:35 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// static int	try_read(int fd, char **line)
// {
// 	char	*buffer;
// 	char	*temp;
// 	int		i;

// 	buffer = (char *)malloc(sizeof(char) * 2);
// 	if (!buffer)
// 		return (-1);
// 	ft_bzero(buffer, 2);
// 	i = read(fd, buffer, 1);
// 	while (i > 0)
// 	{
// 		if (buffer[0] == '\n')
// 			break ;
// 		if (buffer[0] != '0' || buffer[0] != '1' || buffer[0] != 'C'
// 			|| buffer[0] != 'E' || buffer[0] != 'P')
// 			i = -1;
// 		if (i == -1)
// 			break ;
// 		temp = *line;
// 		*line = ft_strjoin(*line, buffer);
// 		free(temp);
// 		i = read(fd, buffer, 1);
// 	}
// 	free(buffer);
// 	return (i);
// }

// char	*get_next_line(int fd)
// {
// 	char	*line;
// 	int		i;

// 	line = (char *)malloc(sizeof(char) * 2);
// 	if (!line)
// 		return (NULL);
// 	ft_bzero(line, 2);
// 	i = try_read(fd, &line);
// 	if (i == -1)
// 		free(line);
// 	if (i == -1)
// 		return (NULL);
// 	return (line);
// }

static void	free_gnl(char *line, char *buffer)
{
	if (line)
		free(line);
	if (buffer)
		free(buffer);
}

static char	*found_newline(char **line, char **remainder, char **buffer)
{
	char	*buffer_start;
	char	*temp;
	int		i;

	i = 0;
	while ((*buffer)[i] != '\n')
		i++;
	buffer_start = ft_substr(*buffer, 0, i);
	if (!buffer_start)
	{
		free_gnl(*line, *buffer);
		return (NULL);
	}
	if ((int)ft_strlen(*buffer) > i + 1)
		*remainder = ft_substr(*buffer, i + 1, ft_strlen(*buffer));
	free(*buffer);
	temp = *line;
	*line = ft_strjoin(*line, buffer_start);
	free_gnl(temp, buffer_start);
	return (*line);
}

static void	gnl_loop(int fd, char **line, char **remainder, char **buffer)
{
	ssize_t	i;

	i = ft_strlen(*buffer);
	while (i > 0)
	{
		if (ft_strchr(*buffer, '\n'))
		{
			*line = found_newline(line, remainder, buffer);
			return ;
		}
		*line = ft_strjoin(*line, *buffer);
		i = read(fd, *buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free_gnl(*line, *buffer);
			return ;
		}
		(*buffer)[i] = '\0';
	}
	free(*buffer);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	ssize_t		i;
	char		*buffer;
	char		*line;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd >= 0 && BUFFER_SIZE > 0 && buffer)
		i = read(fd, buffer, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer || i <= 0)
	{
		free_gnl(remainder, buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	if (!remainder)
		line = ft_strdup("");
	else
		line = ft_strdup(remainder);
	if (!line)
		free_gnl(remainder, buffer);
	if (!line)
		return (NULL);
	free_gnl(remainder, NULL);
	gnl_loop(fd, &line, &remainder, &buffer);
	return (line);
}
