/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:58:04 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/05 10:48:17 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**free_map(char **map)
{
	int	i;

	if (!map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

char	**init_map(int fd)
{
	char	**map;
	char	*line;
	char	*trimmed_line;
	size_t	line_len;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	trimmed_line = ft_strtrim(line, " \n\t\v\f\r");
	if (!trimmed_line)
		free(line);
	if (!trimmed_line)
		return (NULL);
	map = ft_calloc(2, sizeof(char *));
	if (!map)
		free(trimmed_line);
	if (!map)
		return (NULL);
	map[0] = trimmed_line;
	return (map);
}

char	**add_line_to_map(char **map, char *line, int i)
{
	char	**temp;
	char	*trimmed_line;

	temp = ft_calloc(i + 1, sizeof(char *));
	if (!temp)
		return (NULL);
	trimmed_line = ft_strtrim(line, " \n\t\v\f\r");
	if (!trimmed_line)
	{
		free(temp);
		return (NULL);
	}
	i = -1;
	while (map[++i])
		temp[i] = map[i];
	temp[i++] = trimmed_line;
	return (temp);
}

char	**create_map(int fd)
{
	char	**map;
	char	**temp;
	char	*line;
	int		i;

	map = init_map(fd);
	if (!map)
		return (NULL);
	i = 2;
	line = get_next_line(fd);
	while (line)
	{
		temp = add_line_to_map(map, line, i);
		if (!temp)
			free(line);
		if (!temp)
			return (free_map(map));
		free(map);
		map = temp;
		i++;
		line = get_next_line(fd);
	}
	if (!valid_map(map))
		return (free_map(map));
	return (map);
}
