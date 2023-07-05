/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:57:12 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/05 12:29:15 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_lines(char **map)
{
	int	row;

	row = 0;
	while (map[row])
		row++;
	return (row);
}

int	reachable_goals(t_game *game, t_coord *exit_pos, t_coord **collectibles)
{
	int	i;
	int	collectibles_reachable;

	i = 0;
	collectibles_reachable = 0;
	while (collectibles[i])
	{
		if (found_path(game, game->player, collectibles[i]))
			collectibles_reachable++;
		i++;
	}
	if (collectibles_reachable != game->collectibles
		|| !found_path(game, game->player, exit_pos))
		collectibles = free_ls_coord(collectibles);
	if (!collectibles)
		return (0);
	return (1);
}

int	valid_map_layout(t_game *game)
{
	t_coord	*player_pos;
	t_coord	**collectibles;
	t_coord	*exit_pos;

	player_pos = get_pos(game->map, 'P');
	if (!player_pos)
		return (0);
	exit_pos = get_pos(game->map, 'E');
	if (!exit_pos)
		free(player_pos);
	if (!exit_pos)
		return (0);
	collectibles = get_collectibles(game->map);
	if (!collectibles)
	{
		free(player_pos);
		free(exit_pos);
		return (0);
	}
	game->player = player_pos;
	game->collectibles = count_char(game->map, 'C');
	game->width = ft_strlen(game->map[0]);
	game->height = count_lines(game->map);
	return (reachable_goals(game, exit_pos, collectibles));
}
