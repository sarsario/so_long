/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:16:29 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/14 15:14:58 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// Too long! Break it up into smaller functions.
int	ft_valid_map(int fd, char **error_msg, t_game *game)
{
	char	*line;
	int		ret;
	int		i;

	i = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
		{
			*error_msg = "Error\nFile could not be read\n";
			return (0);
		}
		if (i == 0)
			game->width = ft_strlen(line);
		else if (game->width != ft_strlen(line))
		{
			*error_msg = "Error\nInvalid map\n";
			return (0);
		}
		i++;
		free(line);
	}
	game->height = i;
	return (1);
}

int	ft_valid_file(char *file, char **error_msg, t_game *game)
{
	int	fd;

	if (ft_strncmp(&file[ft_strlen(file) - 4], ".ber", 4) != 0)
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
		return (0);
	return (1);
}
