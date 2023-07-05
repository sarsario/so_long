/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:09:38 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/05 11:59:24 by osarsari         ###   ########.fr       */
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
	if (count_char(map, 'P') != 1 || count_char(map, 'E') != 1
		|| count_char(map, 'C') < 1)
		return (0);
	return (1);
}

t_coord	*get_pos(char **map, char c)
{
	t_coord	*pos;
	int		row;
	int		col;

	pos = (t_coord *)malloc(sizeof(t_coord));
	if (!pos)
		return (NULL);
	row = -1;
	while (map[++row])
	{
		col = -1;
		while (map[row][++col])
		{
			if (map[row][col] == c)
			{
				pos->x = col;
				pos->y = row;
				return (pos);
			}
		}
	}
	if (pos)
		free(pos);
	return (NULL);
}

t_coord	**free_ls_coord(t_coord **ls)
{
	int	i;

	if (!ls)
		return (NULL);
	i = 0;
	while (ls[i])
	{
		free(ls[i]);
		i++;
	}
	free(ls);
	return (NULL);
}

t_coord	**get_collectibles(char **map)
{
	t_coord	**collectibles;
	int		row;
	int		col;

	collectibles = ft_calloc(count_char(map, 'C') + 1, sizeof(t_coord *));
	if (!collectibles)
		return (NULL);
	row = -1;
	while (map[++row])
	{
		col = -1;
		while (map[row][++col])
		{
			if (map[row][col] == 'C')
			{
				collectibles[row] = (t_coord *)malloc(sizeof(t_coord));
				if (!collectibles[row])
					return (free_ls_coord(collectibles));
				collectibles[row]->x = col;
				collectibles[row]->y = row;
			}
		}
	}
	return (collectibles);
}
