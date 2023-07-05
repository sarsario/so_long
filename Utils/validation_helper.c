/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:04:48 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/05 20:09:57 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_lines(char **map)
{
	int	row;

	if (!map)
		return (0);
	row = 0;
	while (map[row])
		row++;
	return (row);
}

int	count_char(char **map, char c)
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
	return (count);
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
