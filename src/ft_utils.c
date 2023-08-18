/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:09:44 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/18 12:31:31 by osarsari         ###   ########.fr       */
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
	if (game->win)
		free(game->win);
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

int	get_next_line(int fd, char **line, char **error_msg)
{
	char	*buffer;
	int		i;
	int		r;

	buffer = ft_calloc(50, sizeof(char));
	if (!buffer)
	{
		*error_msg = "Error\nMalloc failed\n";
		return (-1);
	}
	i = 0;
	r = read(fd, &buffer[i], 1);
	while (r > 0 && buffer[i] != '\n' && i < 49)
		r = read(fd, &buffer[++i], 1);
	if (r == -1)
	{
		*error_msg = "Error\nRead failed\n";
		free(buffer);
		return (-1);
	}
	if (r == 0 && i == 0)
	{
		free(buffer);
		return (0);
	}
	if (buffer[i] == '\n')
		buffer[i] = '\0';
	*line = buffer;
	printf("line: %s\n", *line);
	printf("get_next_line returned: %d\n", r);
	return (r);
}
