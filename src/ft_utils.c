/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:09:44 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/17 18:55:14 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = -1;
		while (game->map[++i])
			free(game->map[i]);
		free(game->map);
	}
	if (game->win)
		free(game->win);
	if (game->mlx)
		free(game->mlx);
}

int	ft_error(t_game *game, char *str)
{
	ft_free(game);
	ft_putstr_fd(str, 2);
	return (1);
}