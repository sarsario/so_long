/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:09:44 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/22 10:10:15 by osarsari         ###   ########.fr       */
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
	if (game->img_set.exit.img)
		mlx_destroy_image(game->mlx, game->img_set.exit.img);
	if (game->img_set.floor.img)
		mlx_destroy_image(game->mlx, game->img_set.floor.img);
	if (game->img_set.food.img)
		mlx_destroy_image(game->mlx, game->img_set.food.img);
	if (game->img_set.player.img)
		mlx_destroy_image(game->mlx, game->img_set.player.img);
	if (game->img_set.wall.img)
		mlx_destroy_image(game->mlx, game->img_set.wall.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
}

int	ft_error(t_game *game, char *str)
{
	if (game)
		ft_free(game);
	ft_putstr_fd(str, 2);
	return (1);
}

char	*ft_realloc(char *str, int size)
{
	char	*new;
	int		i;

	new = ft_calloc(size + 1, sizeof(char));
	if (!new)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (str[++i])
		new[i] = str[i];
	free(str);
	return (new);
}

char	*gnl_return(char **line, char *c, int i)
{
	if (i == 0 && *c == '\n')
	{
		*line[i] = *c;
		return (*line);
	}
	if (i == 0)
	{
		free(*line);
		return (NULL);
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	char	c;
	char	*line;
	int		i;

	line = ft_calloc(1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			break ;
		line = ft_realloc(line, i + 2);
		if (!line)
			return (NULL);
		line[i++] = c;
	}
	return (gnl_return(&line, &c, i));
}
