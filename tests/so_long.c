/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:49:51 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/05 11:05:01 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	null_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->player = NULL;
	game->collectibles = 0;
	game->moves = 0;
}

void	loop_game(t_game *game)
{
	if (!valid_map_layout(game))
	{
		ft_putstr_fd("Error\nInvalid map layout\n", 2);
		free_map(game->map);
		return ;
	}
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 64, game->height * 64,
			"so_long");
	mlx_loop(game->mlx);
}
