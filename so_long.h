/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:29:19 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/20 21:19:38 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./MiniLibX/mlx.h"
# include "./Lib/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

// # define ESC 53
// # define W 13
// # define A 0
// # define S 1
// # define D 2

// # define TILE_SIZE 64
// # define WINDOW_WIDTH 640
// # define WINDOW_HEIGHT 480

typedef struct s_map {
	char	**map;
	int		width;
	int		height;
}			t_map;

char	*get_next_line(int fd);

// typedef struct s_player {
// 	int	x;
// 	int	y;
// }		t_player;

// typedef struct s_img {
// 	void	*img;
// 	char	*addr;
// 	int		bpp;
// 	int		line_len;
// 	int		endian;
// }			t_img;

// typedef struct s_game {
// 	void		*mlx;
// 	void		*win;
// 	t_map		map;
// 	t_player	player;
// 	t_img		img;
// }				t_game;


#endif