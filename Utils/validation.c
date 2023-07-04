/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:48:52 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/04 16:18:13 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valid_extension(const char *file)
{
	int	i;

	if (!file)
		return (0);
	i = ft_strlen(file);
	if (i < 5)
		return (0);
	if (file[i - 1] == 'r' && file[i - 2] == 'e'
		&& file[i - 3] == 'b' && file[i - 4] == '.')
		return (1);
	return (0);
}

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

int	duplicate_char(char **map, char c)
{
	int	row;
	int	col;
	int	count;

	if (!map)
		return (0);
	row = -1;
	count = 0;
	while (map[++row])
	{
		col = -1;
		while (map[row][++col])
			if (map[row][col] == c)
				count++;
	}
	if (count > 1)
		return (1);
	return (0);
}