/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:08:33 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/21 18:53:29 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_close(game);
	if (keycode == 13 || keycode == 126)
		ft_move_up(game);
	if (keycode == 1 || keycode == 125)
		ft_move_down(game);
	if (keycode == 0 || keycode == 123)
		ft_move_left(game);
	if (keycode == 2 || keycode == 124)
		ft_move_right(game);
	return (0);
}

int	ft_close(t_game *game)
{
	ft_free(game);
	exit(0);
	return (0);
}
