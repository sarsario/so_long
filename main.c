/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:59:27 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/04 13:09:45 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	null_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->player = NULL;
	game->collectibles = 0;
	game->moves = 0;
}

int	main(int argc, char **argv)
{
	t_file	file;
	t_game	game;

	if (argc != 2)
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
	if (argc != 2)
		return (1);
	if (!valid_extension(argv[1]))
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
	if (!valid_extension(argv[1]))
		return (1);
	file.fd = open(argv[1], O_RDONLY);
	if (file.fd < 0)
		ft_putstr_fd("Error\nInvalid file\n", 2);
	if (file.fd < 0)
		return (1);
	null_game(&game);
	game.map = create_map(file.fd);
	if (game.map == NULL)
		ft_putstr_fd("Error\nInvalid map\n", 2);
	if (game.map == NULL)
		return (1);
	loop_game(&game);
	return (0);
}
