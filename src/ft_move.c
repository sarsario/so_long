/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:09:13 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/21 18:43:24 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		if (game->map[game->player_y][game->player_x] != 'E')
			game->map[game->player_y][game->player_x] = '0';
		ft_draw_map(*game);
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
		if (game->map[game->player_y][game->player_x] != 'E')
			game->map[game->player_y][game->player_x] = '0';
		ft_draw_map(*game);
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
		if (game->map[game->player_y][game->player_x] != 'E')
			game->map[game->player_y][game->player_x] = '0';
		ft_draw_map(*game);
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
		if (game->map[game->player_y][game->player_x] != 'E')
			game->map[game->player_y][game->player_x] = '0';
		ft_draw_map(*game);
	}
}
