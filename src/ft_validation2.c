/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:21:56 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/17 14:24:37 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_enough_elements(char **error_msg, t_game *game)
{
	int	i;
	int	j;
	int	player;
	int	exit;
	int	collect;

	i = -1;
	player = 0;
	exit = 0;
	collect = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
				player++;
			else if (game->map[i][j] == 'E')
				exit++;
			else if (game->map[i][j] == 'C')
				collect++;
		}
	}
	if (player != 1 || exit != 1 || collect < 1)
	{
		*error_msg = "Error\nNot enough elements in map\n";
		return (0);
	}
	return (1);
}
