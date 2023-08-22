/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_image2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:44:13 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/22 14:58:51 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_init_sleep(t_game *game)
{
	game->img_set->sleep = malloc(sizeof(t_img));
	if (!game->img_set->sleep)
		return (0);
	game->img_set->sleep->img = mlx_xpm_file_to_image(
			game->mlx,
			"./src/images/sleep.xpm",
			&(game->img_set->sleep->width), &(game->img_set->sleep->height));
	if (!game->img_set->sleep->img)
		return (0);
	return (1);
}

int	ft_init_eat(t_game *game)
{
	game->img_set->eat = malloc(sizeof(t_img));
	if (!game->img_set->eat)
		return (0);
	game->img_set->eat->img = mlx_xpm_file_to_image(
			game->mlx,
			"./src/images/eat.xpm",
			&(game->img_set->eat->width), &(game->img_set->eat->height));
	if (!game->img_set->eat->img)
		return (0);
	return (1);
}
