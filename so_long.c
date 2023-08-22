/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:55:27 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/22 10:38:59 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->height = 0;
	game->width = 0;
	game->player = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->moves = 0;
	game->collectibles = 0;
	game->exit = 0;
	game->img_set.exit.img = NULL;
	game->img_set.floor.img = NULL;
	game->img_set.food.img = NULL;
	game->img_set.player.img = NULL;
	game->img_set.wall.img = NULL;
}

int	main(int argc, char **argv)
{
	t_game		game;
	char		*error_msg;

	ft_init_game(&game);
	if (argc != 2)
		return (ft_error(NULL, "Error\nInvalid number of arguments\n"));
	if (!ft_valid_file(argv[1], &error_msg, &game))
		return (ft_error(&game, error_msg));
	if (!ft_init_window(&game, &error_msg))
		return (ft_error(&game, error_msg));
	if (!ft_init_images(&game, &error_msg))
		return (ft_error(&game, error_msg));
	ft_draw_map(game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game);
	mlx_hook(game.win, 17, 1L << 17, ft_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
