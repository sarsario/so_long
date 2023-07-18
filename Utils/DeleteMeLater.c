/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DeleteMeLater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:07:57 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/05 20:09:48 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_map(char **map)
{
	int	row;

	if (!map)
		return (0);
	row = -1;
	while (map[++row])
	{
		if (!valid_line(map[row]))
			return (0);
	}
	if (!rectangular_map(map))
		return (0);
	if (!walled_map(map))
		return (0);
	if (count_char(map, 'P') != 1 || count_char(map, 'E') != 1
		|| count_char(map, 'C') < 1)
		return (0);
	return (1);
}

t_coord	**free_ls_coord(t_coord **ls)
{
	int	i;

	if (!ls)
		return (NULL);
	i = 0;
	while (ls[i])
	{
		free(ls[i]);
		i++;
	}
	free(ls);
	return (NULL);
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
