/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:29:19 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/18 12:06:12 by osarsari         ###   ########.fr       */
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

# define MAX_BUFFER_SIZE 8192
# define MIN_BUFFER_SIZE 1
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# else
#  if BUFFER_SIZE < 1
#   undef BUFFER_SIZE
#   define BUFFER_SIZE MIN_BUFFER_SIZE
#  endif
#  if BUFFER_SIZE > 8192
#   undef BUFFER_SIZE
#   define BUFFER_SIZE MAX_BUFFER_SIZE
#  endif
# endif

typedef struct s_coord {
	int	x;
	int	y;
}		t_coord;

typedef struct s_game {
	void		*mlx;
	void		*win;
	char		**map;
	int			width;
	int			height;
	t_coord		player;
	t_coord		exit;
	int			collectibles;
	int			moves;
}				t_game;

int		ft_exit(t_game *game, char *message);

#endif