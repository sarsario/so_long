/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:28:28 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/19 14:10:36 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_init_window(t_game *game, char **error_msg)
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
        game->height * 32,
        "so_long");
    if (!game->win)
    {
        *error_msg = "Error\nmlx_new_window() failed\n";
        return (0);
    }
    return (1);
}
