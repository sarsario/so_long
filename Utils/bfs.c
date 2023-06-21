/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:54:05 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/21 23:05:19 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	**init_visited(t_game *game)
{
	int	**visited;
	int	i;
	int	j;

	visited = malloc(sizeof(int *) * game->map->height);
	if (!visited)
		return (0);
	i = -1;
	while (++i < game->map->height)
	{
		visited[i] = malloc(sizeof(int) * game->map->width);
		if (!visited[i])
		{
			while (i--)
				free(visited[i]);
			free(visited);
			return (0);
		}
		j = -1;
		while (++j < game->map->width)
			visited[i][j] = 0;
	}
	return (visited);
}

int	in_bound(t_game *game, t_coord *coord)
{
	if (coord->x >= 0 && coord->x < game->map->width && coord->y >= 0
		&& coord->y < game->map->height)
		return (1);
	return (0);
}
