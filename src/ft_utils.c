/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:09:44 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/22 15:00:50 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_map(t_game *game)
{
	int	i;

	if (game && game->map)
	{
		i = -1;
		while (game->map[++i])
			free(game->map[i]);
		free(game->map);
	}
}

void	ft_free_img(t_game *game)
{
	if (game && game->img_set)
	{
		if (game->img_set->exit && game->img_set->exit->img)
			mlx_destroy_image(game->mlx, game->img_set->exit->img);
		if (game->img_set->exit && game->img_set->exit->img)
			free(game->img_set->exit);
		if (game->img_set->floor && game->img_set->floor->img)
			mlx_destroy_image(game->mlx, game->img_set->floor->img);
		if (game->img_set->floor && game->img_set->floor->img)
			free(game->img_set->floor);
		if (game->img_set->food && game->img_set->food->img)
			mlx_destroy_image(game->mlx, game->img_set->food->img);
		if (game->img_set->food && game->img_set->food->img)
			free(game->img_set->food);
		if (game->img_set->player && game->img_set->player->img)
			mlx_destroy_image(game->mlx, game->img_set->player->img);
		if (game->img_set->player && game->img_set->player->img)
			free(game->img_set->player);
		if (game->img_set->wall && game->img_set->wall->img)
			mlx_destroy_image(game->mlx, game->img_set->wall->img);
		if (game->img_set->wall && game->img_set->wall->img)
			free(game->img_set->wall);
		free(game->img_set);
	}
}

void	ft_free_extra_img(t_game *game)
{
	if (game && game->img_set)
	{
		if (game->img_set->sleep && game->img_set->sleep->img)
			mlx_destroy_image(game->mlx, game->img_set->sleep->img);
		if (game->img_set->sleep && game->img_set->sleep->img)
			free(game->img_set->sleep);
		if (game->img_set->eat && game->img_set->eat->img)
			mlx_destroy_image(game->mlx, game->img_set->eat->img);
		if (game->img_set->eat && game->img_set->eat->img)
			free(game->img_set->eat);
	}
}

void	ft_free(t_game *game)
{
	ft_free_map(game);
	ft_free_extra_img(game);
	ft_free_img(game);
	if (game && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game && game->mlx)
		free(game->mlx);
	if (game)
		free(game);
}

int	ft_error(t_game *game, char *str)
{
	if (game)
		ft_free(game);
	ft_putstr_fd(str, 2);
	return (1);
}
