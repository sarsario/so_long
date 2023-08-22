/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:28:28 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/22 16:10:54 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_init_window(t_game *game, char **error_msg)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		*error_msg = "Error\nmlx_init() failed\n";
		return (0);
	}
	game->win = mlx_new_window(
			game->mlx,
			game->width * 32,
			game->height * 32 + 32,
			"so_long");
	if (!game->win)
	{
		*error_msg = "Error\nmlx_new_window() failed\n";
		return (0);
	}
	return (1);
}

int	ft_init_images(t_game *game, char **error_msg)
{
	game->img_set = malloc(sizeof(t_img_set));
	if (!game->img_set)
	{
		*error_msg = "Error\nMalloc failed\n";
		return (0);
	}
	if (!ft_init_exit(game) || !ft_init_floor(game) || !ft_init_food(game)
		|| !ft_init_player(game) || !ft_init_wall(game) || !ft_init_sleep(game)
		|| !ft_init_eat(game) || !ft_init_enemy(game) || !ft_init_bg(game))
	{
		*error_msg = "Error\nmlx_xpm_file_to_image() failed\n";
		return (0);
	}
	return (1);
}

void	ft_draw_npc(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_set->wall->img, x * 32, y * 32);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_set->food->img, x * 32 + 8, y * 32 + 8);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_set->exit->img, x * 32, y * 32);
	else if (game->map[y][x] == 'X')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_set->enemy->img, x * 32, y * 32);
}

void	ft_draw_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_set->floor->img, x * 32, y * 32);
			ft_draw_npc(game, x, y);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_set->player->img,
		game->player_x * 32, game->player_y * 32 - 8);
	ft_print_move(game);
}

void	ft_print_move(t_game *game)
{
	char	*move;
	char	*tmp;
	int		x;

	move = ft_itoa(game->moves);
	if (!move)
		ft_error(game, "Error\nMalloc failed\n");
	tmp = ft_strjoin("Moves: ", move);
	if (!tmp)
		free(move);
	if (!tmp)
		ft_error(game, "Error\nMalloc failed\n");
	x = -1;
	while (++x < game->width)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_set->bg->img, x * 32, game->height * 32);
	mlx_string_put(game->mlx, game->win, x - 1, game->height * 32 + 10,
		0x00000000, tmp);
	free(move);
	free(tmp);
}
