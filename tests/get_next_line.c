/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:38:16 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/04 10:43:20 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_newline(t_file *file)
{
	int	nl_pos;

	if (file->fd == -1 || !file->buffer[0])
		return (-1);
	nl_pos = 0;
	while (file->buffer[nl_pos] && file->buffer[nl_pos] != '\n')
		nl_pos++;
	if (file->buffer[nl_pos] == '\n')
		return (nl_pos);
	return (-1);
}

char	*my_get_line(t_file *file)
{
	char	*line;
	int		nl_pos;
	int		i;

	if (file->fd == -1 || !file->buffer[0])
		return (NULL);
	nl_pos = check_newline(file);
	line = malloc(sizeof(char) * (2 + nl_pos));
	if (!line)
		return (NULL);
	i = -1;
	while (++i <= nl_pos)
		line[i] = file->buffer[i];
	line[i] = 0;
	ft_substr2(file, nl_pos);
	return (line);
}

int	read_success(t_file *file, char *s)
{
	if (file->bytes_read == -1)
	{
		file->buffer[0] = 0;
		if (s)
			free(s);
		return (0);
	}
	return (1);
}

char	*read_file(t_file *file)
{
	char	*line;

	line = NULL;
	if (file->fd == -1)
		return (NULL);
	if (file->buffer[0])
		line = ft_strdup2(file->buffer);
	file->bytes_read = read(file->fd, file->buffer, BUFFER_SIZE);
	if (!read_success(file, line))
		return (NULL);
	file->buffer[file->bytes_read] = 0;
	while (file->bytes_read > 0 && check_newline(file) == -1)
	{
		line = ft_strjoin2(line, file->buffer);
		file->bytes_read = read(file->fd, file->buffer, BUFFER_SIZE);
		if (file->bytes_read > -1)
			file->buffer[file->bytes_read] = 0;
	}
	if (check_newline(file) != -1)
		line = ft_join_free(line, my_get_line(file));
	else if (file->buffer[0])
		file->buffer[0] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static t_file	files[MAX_FD] = {[0 ...MAX_FD - 1] = {.fd = -1}};
	t_file			*current_file;
	int				file_index;

	if (fd < 0 || fd >= MAX_FD)
		return (NULL);
	if (files[fd].fd == -1)
		files[fd].fd = fd;
	file_index = files[fd].fd;
	if (file_index < 0)
		return (NULL);
	current_file = &files[fd];
	if (current_file->buffer[0] && check_newline(current_file) >= 0)
		return (my_get_line(current_file));
	return (read_file(current_file));
}
