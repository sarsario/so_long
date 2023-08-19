/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:29:19 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/19 15:06:48 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./lib/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>

typedef struct s_game {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	**map;
	int		collectibles;
	int		player;
	int		exit;
	int		moves;
	int		player_x;
	int		player_y;
}			t_game;

typedef struct s_img {
	void	*img;
	int		width;
	int		height;
}			t_img;

typedef struct s_img_set {
	t_img	*idle1;
	t_img	*idle2;
	t_img	*idle3;
	t_img	*idle4;
	t_img	*run1;
	t_img	*run2;
	t_img	*run3;
	t_img	*run4;
	t_img	*run5;
	t_img	*run6;
	t_img	*run7;
	t_img	*run8;
	t_img	*run9;
	t_img	*food;
	t_img	*border_bottom_left;
	t_img	*border_bottom_right;
	t_img	*border_bottom;
	t_img	*border_left;
	t_img	*border_right;
	t_img	*border_top_left;
	t_img	*border_top_right;
	t_img	*border_top;
	t_img	*door_opened;
	t_img	*door;
	t_img	*floor;
	t_img	*wall_top_left;
	t_img	*wall_top_right;
	t_img	*wall_top;
}			t_img_set;

int		ft_error(t_game *game, char *str);
void	ft_array_free(char **array);
int		ft_array_len(char **array);
char	**ft_array_dup(char **array);
int		ft_array_join(char ***array, char *str);
char	*get_next_line(int fd);
int		ft_valid_line(char *line, char **error_msg);
int		ft_enough_elements(char **error_msg, t_game *game);
int		ft_valid_path(char **error_msg, t_game *game);
int		ft_valid_file(char *file, char **error_msg, t_game *game);
int		ft_init_window(t_game *game, char **error_msg);

#endif