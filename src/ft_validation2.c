/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:21:56 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/17 16:52:58 by osarsari         ###   ########.fr       */
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
				set_player(game, i, j);
			else if (game->map[i][j] == 'E')
				game.exit++;
			else if (game->map[i][j] == 'C')
				game->collectibles++;
		}
	}
	if (game.player != 1 || game.exit != 1 || game->collectibles < 1)
	{
		*error_msg = "Error\nNot enough elements in map\n";
		return (0);
	}
	return (1);
}

int	ft_check_path(char **map, int x, int y, int c)
{
	
}

int	ft_valid_path(char **error_msg, t_game *game)
{
	char	**map_cpy;
	int		check_point;

	map_cpy = ft_array_dup(game->map);
	if (!map_cpy)
		return (0);
	check_point = game->collectibles + game->exit;
	if (!ft_check_path(map_cpy, game->player_x, game->player_y, check_point))
	{
		*error_msg = "Error\nMap unsolvable\n";
		ft_array_free(map_cpy);
		return (0);
	}
	ft_array_free(map_cpy);
	return (1);
}
