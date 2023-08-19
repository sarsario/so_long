/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:21:56 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/19 15:29:14 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	set_player(t_game *game, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	game->player++;
	return (1);
}

int	ft_enough_elements(char **error_msg, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
				set_player(game, j, i);
			else if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] == 'C')
				game->collectibles++;
		}
	}
	if (game->player != 1 || game->exit != 1 || game->collectibles < 1)
	{
		*error_msg = "Error\nNot enough elements in map\n";
		return (0);
	}
	return (1);
}

int	ft_check_path(char **map, int x, int y, int *c)
{
	if (map[x][y] == 'E' || map[x][y] == 'C')
		(*c)--;
	if (*c == 0)
		return (1);
	map[x][y] = '1';
	if (x > 0 && map[x - 1][y] != '1' && ft_check_path(map, x - 1, y, c))
		return (1);
	if (y > 0 && map[x][y - 1] != '1' && ft_check_path(map, x, y - 1, c))
		return (1);
	if (x < ft_array_len(map) - 2 && map[x + 1][y] != '1'
		&& ft_check_path(map, x + 1, y, c))
		return (1);
	if (y < (int)ft_strlen(map[x]) - 2 && map[x][y + 1] != '1'
		&& ft_check_path(map, x, y + 1, c))
		return (1);
	return (0);
}

int	ft_valid_path(char **error_msg, t_game *game)
{
	char	**map_cpy;
	int		check_point;

	map_cpy = ft_array_dup(game->map);
	if (!map_cpy)
	{
		*error_msg = "Error\nMalloc failed\n";
		return (0);
	}
	check_point = game->collectibles + game->exit;
	if (!ft_check_path(map_cpy, game->player_y, game->player_x, &check_point))
	{
		*error_msg = "Error\nMap unsolvable\n";
		ft_array_free(map_cpy);
		return (0);
	}
	ft_array_free(map_cpy);
	return (1);
}

int	ft_valid_line(char *line, char **error_msg)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P')
		{
			*error_msg = "Error\nInvalid character in map\n";
			free(line);
			return (0);
		}
		i++;
	}
	if (i < 3)
	{
		*error_msg = "Error\nMap is too small\n";
		free(line);
		return (0);
	}
	return (1);
}
