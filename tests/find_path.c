/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:29:27 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/05 17:36:04 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	**free_visited(int **visited, int height)
{
	int	row;

	if (!visited)
		return (NULL);
	row = 0;
	while (row < height)
	{
		if (visited[row])
			free(visited[row]);
		row++;
	}
	free(visited);
	return (NULL);
}

int	**init_visited(t_game *game)
{
	int	**visited;
	int	row;

	if (!game || !game->map || !game->height || !game->width)
		return (NULL);
	visited = ft_calloc(game->height, sizeof(int *));
	if (!visited)
		return (NULL);
	row = 0;
	while (row < game->height)
	{
		visited[row] = ft_calloc(game->width, sizeof(int));
		if (!visited[row])
			return (free_visited(visited, row));
		row++;
	}
	return (visited);
}

int	found_path(t_game *game, t_coord *start, t_coord *end)
{
	int		**visited;
	int		row;
	int		col;

	visited = init_visited(game);
	if (!visited)
		return (0);
	visited[start->y][start->x] = 1;
	if (start->x == end->x && start->y == end->y)
		return (1);
	
}
