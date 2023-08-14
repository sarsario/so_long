/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:29:19 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/14 14:57:50 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./MiniLibX/mlx.h"
# include "./Lib/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>

typedef struct s_coord {
	int	x;
	int	y;
}		t_coord;

typedef struct s_game {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}			t_game;

int	ft_valid_file(char *file, char **error_msg, t_game *game);
int	ft_error(char *str);

#endif