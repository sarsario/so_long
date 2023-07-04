/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:09:38 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/04 17:14:26 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	walled_map(char **map)
{
	int	row;
	int	max_row;
	int	col;

	if (!map)
		return (0);
	row = 0;
	col = ft_strlen(map[row]);
	while (map[row])
	{
		if (map[row][0] != '1' || map[row][col - 1] != '1')
			return (0);
		row++;
	}
	max_row = row - 1;
	row = 0;
	while (row < col)
	{
		if (map[0][row] != '1' || map[max_row][row] != '1')
			return (0);
		row++;
	}
	return (1);
}

int	valid_map(char **map)
{
	int	row;

	if (!map)
		return (0);
	row = -1;
	while (map[++row])
	{
		if (!valid_line(map[row]))
			return (0);
	}
	if (!rectangular_map(map))
		return (0);
	if (!walled_map(map))
		return (0);
	if (duplicate_char(map, 'P') || duplicate_char(map, 'E'))
		return (0);
	return (1);
}
