/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:48:52 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/21 12:31:06 by osarsari         ###   ########.fr       */
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

void	try_create_rectangle(int fd, t_map *map)
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
		add_row(map, line);
	}
}

t_map	*create_valid_map(int fd)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	try_create_rectangle(fd, map);
	if (!playable_map(map))
		free_map(map);
	if (!map)
		return (NULL);
	return (map);
}

t_map	*create_map(const char *file)
{
	int		fd;
	t_map	*map;

	if (!valid_extension(file))
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = create_valid_map(fd);
	close(fd);
	return (map);
}

// int	rectangular_map(int fd)
// {
// 	char	*line;
// 	int		i;
// 	int		j;
// 	int		flag;

// 	i = 0;
// 	j = 0;
// 	flag = 0;
// 	line = get_next_line(fd);
// 	while (line && !flag)
// 	{
// 		if (i == 0)
// 			j = ft_strlen(line);
// 		else if (j != ft_strlen(line))
// 			flag = 1;
// 		i++;
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	if (line)
// 		free(line);
// 	return (i > 3 && !flag);
// }
