/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:58:04 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/21 11:22:00 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = -1;
	if (map->map)
	{
		while (++i < map->height)
		{
			if (map->map[i])
				free(map->map[i]);
		}
		free(map->map);
	}
	free(map);
}
