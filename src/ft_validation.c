/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:16:29 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/18 12:32:36 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		if (game->width != (int)ft_strlen(game->map[i]))
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

int	ft_valid_rules(char **error_msg, t_game *game)
{
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

int	ft_valid_map(int fd, char **error_msg, t_game *game)
{
	printf("Validating map...\n");
	char	*line;

	*error_msg = NULL;
	while (!*error_msg && get_next_line(fd, &line, error_msg) > 0)
	{
		printf("Line: %s\n", line);
		if (!ft_valid_line(line, error_msg))
			return (0);
		printf("Line is valid\n");
		if (!ft_array_join(&(game->map), line))
		{
			*error_msg = "Error\nMap could not be allocated\n";
			free(line);
			return (0);
		}
		printf("Line added to map\n");
	}
	if (*error_msg)
		return (0);
	if (!ft_valid_line(line, error_msg))
		return (0);
	printf("Line is valid\n");
	if (!ft_array_join(&(game->map), line))
	{
		*error_msg = "Error\nMap could not be allocated\n";
		free(line);
		return (0);
	}
	printf("Line added to map\n");
	if (!ft_valid_rules(error_msg, game))
		return (0);
	printf("Map is valid\n");
	return (1);
}

int	ft_valid_file(char *file, char **error_msg, t_game *game)
{
	printf("Validating file...\n");
	int	fd;

	printf("File: %s\n", file);
	printf("File length: %zu\n", ft_strlen(file));
	printf("File extension: %s\n", &file[ft_strlen(file) - 4]);
	printf("ft_strncmp: %d\n", ft_strncmp(&file[ft_strlen(file) - 4], ".ber", 4));
	if (ft_strlen(file) < 5
		|| ft_strncmp(&file[ft_strlen(file) - 4], ".ber", 4))
	{
		*error_msg = "Error\nInvalid file extension\n";
		return (0);
	}
	printf("File extension is valid\n");
	printf("Opening file...\n");
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		*error_msg = "Error\nFile could not be opened\n";
		return (0);
	}
	printf("File opened\n");
	if (!ft_valid_map(fd, error_msg, game))
	{
		close(fd);
		return (0);
	}
	close(fd);
	printf("File is valid\n");
	return (1);
}
