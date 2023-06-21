/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:59:09 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/21 13:35:34 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	closed_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (i == 0 || i == map->height - 1)
			{
				if (map->map[i][j] != '1')
					return (0);
			}
			else if (j == 0 || j == map->width - 1)
			{
				if (map->map[i][j] != '1')
					return (0);
			}
		}
	}
	return (1);
}

int	player_map(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] == 'P')
				return (1);
		}
	}
	return (0);
}

int	collectible_map(t_map *map)
{
	int	i;
	int	j;
	int	collectibles;

	collectibles = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] == 'C')
				collectibles++;
		}
	}
	return (collectibles);
}

int	solvable_map(t_map *map)
{
	t_coord	player;
	t_coord	exit;

	player = find_player(map);
	exit = find_exit(map);
	return (player_can_exit(map, player, exit));
}

int	playable_map(t_map *map)
{
	if (!map || !map->map || map->height < 3 || map->width < 3)
		return (0);
	if (!closed_map(map))
		return (0);
	if (!player_map(map))
		return (0);
	if (!collectible_map(map))
		return (0);
	if (!solvable_map(map))
		return (0);
	return (1);
}
