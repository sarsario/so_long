/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:59:27 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/18 11:47:53 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->height = 0;
	game->width = 0;
	game->player = NULL;
	game->exit = NULL;
	game->collectibles = 0;
	game->moves = 0;
}

int	main(int argc, char **argv)
{
	t_file	file;
	t_game	game;

	init_game(&game);
	if (argc != 2)
		return (ft_exit(&game, "Error\nInvalid number of arguments\n"));
	if (!valid_extension(argv[1]))
		return (ft_exit(&game, "Error\nInvalid file extension\n"));
	file->fd = open(argv[1], O_RDONLY);
	if (file->fd < 0)
		return (ft_exit(&game, "Error\nInvalid file\n"));
	return (0);
}
