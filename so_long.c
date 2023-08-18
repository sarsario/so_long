/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:55:27 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/18 11:02:27 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	char	*error_msg;

	game.map = NULL;
	game.height = 0;
	game.width = 0;
	game.player = 0;
	game.collectibles = 0;
	game.exit = 0;
	if (argc != 2)
		return (ft_error(NULL, "Error\nInvalid number of arguments\n"));
	if (!ft_valid_file(argv[1], &error_msg, &game))
		return (ft_error(&game, error_msg));
	return (0);
}
