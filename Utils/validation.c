/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:48:52 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/21 13:44:31 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_extension(const char *file)
{
	int	i;

	if (!file)
		return (0);
	i = 0;
	while (file[i])
		i++;
	if (i < 5)
		return (0);
	if (file[i - 1] == 'r' && file[i - 2] == 'e'
		&& file[i - 3] == 'b' && file[i - 4] == '.')
		return (1);
	return (0);
}

int	added_row(t_map *map, char *line)
{
	char	**temp;
	int		i;

	temp = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!temp)
		return (0);
	if (map->height == 0)
	{
		temp[0] = line;
		map->map = temp;
		map->height++;
		return (1);
	}
	i = -1;
	while (++i < map->height)
		temp[i] = map->map[i];
	temp[i] = line;
	free(map->map);
	map->map = temp;
	map->height++;
	return (1);
}

void	fill_map_from_file(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return ;
	while (line)
	{
		if (map->height == 0)
			map->width = ft_strlen(line);
		else if (map->width != ft_strlen(line))
		{
			free(line);
			free_map(map);
			return ;
		}
		if (!added_row(map, line))
		{
			free(line);
			free_map(map);
			return ;
		}
		line = get_next_line(fd);
	}
}

t_map	*create_valid_map(int fd)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	fill_map_from_file(fd, map);
	if (!playable_map(map))
		free_map(map);
	if (!map)
		return (NULL);
	return (map);
}

int	player_can_exit(t_map *map, t_coord player, t_coord exit)
{
	
}
