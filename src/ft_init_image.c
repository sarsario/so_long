/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:07:09 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/21 17:28:16 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_init_exit(t_game *game)
{
	game->img_set.exit.img = mlx_xpm_file_to_image(
			game->mlx,
			"./src/images/exit.xpm",
			&(game->img_set.exit.width), &(game->img_set.exit.height));
	if (!game->img_set.exit.img)
		return (0);
	return (1);
}

int	ft_init_floor(t_game *game)
{
	game->img_set.floor.img = mlx_xpm_file_to_image(
			game->mlx,
			"./src/images/floor.xpm",
			&(game->img_set.floor.width), &(game->img_set.floor.height));
	if (!game->img_set.floor.img)
		return (0);
	return (1);
}

int	ft_init_food(t_game *game)
{
	game->img_set.food.img = mlx_xpm_file_to_image(
			game->mlx,
			"./src/images/food.xpm",
			&(game->img_set.food.width), &(game->img_set.food.height));
	if (!game->img_set.food.img)
		return (0);
	return (1);
}

int	ft_init_player(t_game *game)
{
	game->img_set.player.img = mlx_xpm_file_to_image(
			game->mlx,
			"./src/images/player.xpm",
			&(game->img_set.player.width), &(game->img_set.player.height));
	if (!game->img_set.player.img)
		return (0);
	return (1);
}

int	ft_init_wall(t_game *game)
{
	game->img_set.wall.img = mlx_xpm_file_to_image(
			game->mlx,
			"./src/images/wall.xpm",
			&(game->img_set.wall.width), &(game->img_set.wall.height));
	if (!game->img_set.wall.img)
		return (0);
	return (1);
}
