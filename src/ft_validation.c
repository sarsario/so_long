/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:16:29 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/17 14:19:42 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_valid_line(char *line, char **error_msg)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P')
		{
			*error_msg = "Error\nInvalid character in map\n";
			free(line);
			return (0);
		}
	}
	if (i < 5)
	{
		*error_msg = "Error\nMap is too small\n";
		free(line);
		return (0);
	}
	return (1);
}

int	ft_valid_size(char **error_msg, t_game *game)
{
	int	i;

	if (!game->map)
	{
		*error_msg = "Error\nMap is empty\n";
		return (0);
	}
	i = -1;
	while (game->map[++i])
	{
		if (game->width == 0)
			game->width = ft_strlen(game->map[i]);
		if (game->width != ft_strlen(game->map[i]))
		{
			*error_msg = "Error\nMap is not rectangular\n";
			return (0);
		}
	}
	game->height = i;
	if (game->height < 5 || game->width < 5)
	{
		*error_msg = "Error\nMap is too small\n";
		return (0);
	}
	return (1);
}

int	ft_closed_map(char **error_msg, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (i == 0 || i == game->height - 1 || j == 0
				|| j == game->width - 1)
			{
				if (game->map[i][j] != '1')
				{
					*error_msg = "Error\nMap is not closed\n";
					return (0);
				}
			}
		}
	}
	return (1);
}

int	ft_valid_map(int fd, char **error_msg, t_game *game)
{
	char	*line;

	game->map = NULL;
	game->height = 0;
	game->width = 0;
	while (get_next_line(fd, &line))
	{
		if (!ft_valid_line(line, error_msg))
			return (0);
		ft_join_array(game->map, line);
	}
	if (!ft_valid_size(error_msg, game))
		return (0);
	if (!ft_closed_map(error_msg, game))
		return (0);
	if (!ft_enough_elements(error_msg, game))
		return (0);
	if (!ft_valid_path(error_msg, game))
		return (0);
	return (1);
}

int	ft_valid_file(char *file, char **error_msg, t_game *game)
{
	int	fd;

	if (ft_strlen(file) < 5
		|| ft_strncmp(&file[ft_strlen(file) - 4], ".ber", 4))
	{
		*error_msg = "Error\nInvalid file extension\n";
		return (0);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		*error_msg = "Error\nFile could not be opened\n";
		return (0);
	}
	if (!ft_valid_map(fd, error_msg, game))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
