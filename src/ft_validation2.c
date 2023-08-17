/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:21:56 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/17 15:03:09 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_enough_elements(char **error_msg, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
				game.player++;
			else if (game->map[i][j] == 'E')
				game.exit++;
			else if (game->map[i][j] == 'C')
				game->collectibles++;
		}
	}
	if (game.player != 1 || game.exit != 1 || game->collectibles < 1)
	{
		*error_msg = "Error\nNot enough elements in map\n";
		return (0);
	}
	return (1);
}
