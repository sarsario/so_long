/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:37:31 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/18 11:50:46 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	free_map(char **map)
{
	int	row;

	if (!map)
		return ;
	row = 0;
	while (map[row])
	{
		free(map[row]);
		row++;
	}
	free(map);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map);
	if (game->mlx)
		free(game->mlx);
	if (game->win)
		free(game->win);
}

int	ft_exit(t_game *game, char *message)
{
	ft_putstr_fd(message, 2);
	free_game(game);
	return (1);
}