/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:09:13 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/22 15:06:06 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_draw_player(t_game *game, int old_x, int old_y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_set->floor->img,
		old_y * 32, old_x * 32);
	if (game->map[old_x][old_y] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_set->exit->img,
			old_y * 32, old_x * 32);
	if (game->map[game->player_y][game->player_x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_set->eat->img,
			game->player_x * 32, game->player_y * 32 - 8);
	else if (game->map[game->player_y][game->player_x] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_set->exit->img,
			game->player_x * 32, game->player_y * 32);
		mlx_put_image_to_window(game->mlx, game->win, game->img_set->sleep->img,
			game->player_x * 32, game->player_y * 32 - 8);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_set->floor->img,
			game->player_x * 32, game->player_y * 32);
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_set->player->img,
			game->player_x * 32, game->player_y * 32 - 8);
	}
}

void	ft_move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		game->player_y--;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->collectibles--;
		else if (game->map[game->player_y][game->player_x] == 'E')
		{
			if (game->collectibles == 0)
				ft_close(game);
		}
		ft_draw_player(game, game->player_y + 1, game->player_x);
		if (game->map[game->player_y][game->player_x] != 'E')
			game->map[game->player_y][game->player_x] = '0';
	}
}

void	ft_move_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		game->player_y++;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->collectibles--;
		else if (game->map[game->player_y][game->player_x] == 'E')
		{
			if (game->collectibles == 0)
				ft_close(game);
		}
		ft_draw_player(game, game->player_y - 1, game->player_x);
		if (game->map[game->player_y][game->player_x] != 'E')
			game->map[game->player_y][game->player_x] = '0';
	}
}

void	ft_move_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		game->player_x--;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->collectibles--;
		else if (game->map[game->player_y][game->player_x] == 'E')
		{
			if (game->collectibles == 0)
				ft_close(game);
		}
		ft_draw_player(game, game->player_y, game->player_x + 1);
		if (game->map[game->player_y][game->player_x] != 'E')
			game->map[game->player_y][game->player_x] = '0';
	}
}

void	ft_move_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		game->player_x++;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		if (game->map[game->player_y][game->player_x] == 'C')
			game->collectibles--;
		else if (game->map[game->player_y][game->player_x] == 'E')
		{
			if (game->collectibles == 0)
				ft_close(game);
		}
		ft_draw_player(game, game->player_y, game->player_x - 1);
		if (game->map[game->player_y][game->player_x] != 'E')
			game->map[game->player_y][game->player_x] = '0';
	}
}
