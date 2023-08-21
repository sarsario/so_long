/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:55:27 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/21 15:39:51 by osarsari         ###   ########.fr       */
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
	void	*floor;
	int		img_width;
	int		img_height;
	floor = mlx_xpm_file_to_image(
		game.mlx,
		"./src/images/floor.xpm",
		&img_width,
		&img_height);
	int		x;
	int		y;
	x = 0;
	y = 0;
	while (y < game.height)
	{
		while (x < game.width)
		{
			mlx_put_image_to_window(game.mlx, game.win, floor, x * 32, y * 32);
			x++;
		}
		x = 0;
		y++;
	}
	void	*wall;
	wall = mlx_xpm_file_to_image(
		game.mlx,
		"./src/images/wall.xpm",
		&img_width,
		&img_height);
	void	*food;
	food = mlx_xpm_file_to_image(
		game.mlx,
		"./src/images/food.xpm",
		&img_width,
		&img_height);
	x = 0;
	y = 0;
	void	*exit;
	exit = mlx_xpm_file_to_image(
		game.mlx,
		"./src/images/exit.xpm",
		&img_width,
		&img_height);
	while (y < game.height)
	{
		while (x < game.width)
		{
			if (game.map[y][x] == '1')
				mlx_put_image_to_window(
					game.mlx,
					game.win,
					wall,
					x * 32,
					y * 32);
			else if (game.map[y][x] == 'C')
				mlx_put_image_to_window(
					game.mlx,
					game.win,
					food,
					x * 32 + 8,
					y * 32 + 8);
			else if (game.map[y][x] == 'E')
				mlx_put_image_to_window(
					game.mlx,
					game.win,
					exit,
					x * 32,
					y * 32);
			x++;
		}
		x = 0;
		y++;
	}
	void	*player;
	player = mlx_xpm_file_to_image(
		game.mlx,
		"./src/images/player.xpm",
		&img_width,
		&img_height);
	mlx_put_image_to_window(
		game.mlx,
		game.win,
		player,
		game.player_x * 32,
		game.player_y * 32 - 8);
	mlx_loop(game.mlx);
	return (0);
}
