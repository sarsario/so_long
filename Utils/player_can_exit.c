/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_can_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:34:10 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/21 23:07:34 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_dx(int *dx)
{
	dx[0] = -1;
	dx[1] = 1;
	dx[2] = 0;
	dx[3] = 0;
}

void	set_dy(int *dy)
{
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = -1;
	dy[3] = 1;
}

int	bfs(t_game *game, t_coord *queue, int **visited, t_coord front_rear)
{
	t_coord	i_j;
	int		dx[4];
	int		dy[4];

	set_dx(dx);
	set_dy(dy);
	queue[front_rear.y++] = game->player;
	visited[game->player->x][game->player->y] = 1;
	while (front_rear.x < front_rear.y)
	{
		i_j = queue[front_rear.x++];
		if (game->map->map[i_j.x][i_j.y] == 'E')
			return (1);
		i_j.i = -1;
		while (++i_j.i < 4)
		{
			i_j.x += dx[i_j.i];
			i_j.y += dy[i_j.i];
			if (i_j.x >= 0 && i_j.x < game->map->height && i_j.y >= 0
				&& i_j.y < game->map->width && game->map->map[i_j.x][i_j.y] != '1'
				&& !visited[i_j.x][i_j.y])
			{
				queue[front_rear.y++] = i_j;
				visited[i_j.x][i_j.y] = 1;
			}
			i_j.x -= dx[i_j.i];
			i_j.y -= dy[i_j.i];
		}
	}
	return (0);
}

// front = x
// rear = y

int	player_can_exit(t_game *game)
{
	t_coord	*queue;
	int		**visited;
	t_coord	i_j;
	t_coord	front_rear;

	queue = malloc(sizeof(t_coord) * (game->map->height * game->map->width));
	if (!queue)
		return (0);
	visited = init_visited(game);
	if (!visited)
		return (0);
	front_rear.x = 0;
	front_rear.y = 0;
	return (bfs(game, queue, visited, front_rear));
}
