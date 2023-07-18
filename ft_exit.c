/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:37:31 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/18 10:39:12 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	ft_exit(t_game *game, char *message)
{
	ft_putstr_fd(message, 2);
	free_game(game);
	return (1);
}