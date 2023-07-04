/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:58:04 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/04 13:48:04 by osarsari         ###   ########.fr       */
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
	size_t	line_len;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	map = malloc(sizeof(char *) * 2);
	if (!map)
	{
		free(line);
		return (NULL);
	}
	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line[line_len - 1] = '\0';
	map[0] = line;
	map[1] = NULL;
	free(line);
	return (map);
}

char	**add_line_to_map(char **map, char *line, int i)
{
	char	**temp;

	temp = malloc(sizeof(char *) * (i + 1));
	if (!temp)
		return (NULL);
	i = -1;
	while (map[++i])
		temp[i] = map[i];
	temp[i++] = line;
	temp[i] = NULL;
	return (temp);
}

void	trim_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (map[i][j - 1] == '\n')
			map[i][j - 1] = '\0';
		i++;
	}
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
	trim_map(map);
	return (map);
}
