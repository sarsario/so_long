/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:48:52 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/05 20:15:07 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

int	valid_line(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (!valid_char(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	rectangular_map(char **map)
{
	int	row;
	int	col;
	int	i;

	if (!map)
		return (0);
	row = 0;
	if (!map[row])
		return (0);
	col = ft_strlen(map[row]);
	while (map[++row])
	{
		i = ft_strlen(map[row]);
		if (i != col)
			return (0);
	}
	if (row < 3 || col < 3 || (row == 3 && col < 6) || (col == 3 && row < 6))
		return (0);
	return (1);
}

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
