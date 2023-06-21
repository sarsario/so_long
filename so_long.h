/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:29:19 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/21 22:55:15 by osarsari         ###   ########.fr       */
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

typedef struct s_coord {
	int	x;
	int	y;
}		t_coord;

typedef struct s_game {
	void		*mlx;
	void		*win;
	t_map		*map;
	t_coord		*player;
	int			collectibles_count;
	int			moves;
}				t_game;

void	free_map(t_map *map);
int		valid_extension(const char *file);
char	*get_next_line(int fd);
int		**init_visited(t_game *game);
int		playable_map(t_map *map);
t_map	*create_valid_map(int fd);
t_map	*create_map(const char *file);

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