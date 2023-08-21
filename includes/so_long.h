/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:29:19 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/21 18:51:26 by osarsari         ###   ########.fr       */
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

typedef struct s_img {
	void	*img;
	int		width;
	int		height;
}			t_img;

typedef struct s_img_set {
	t_img	exit;
	t_img	floor;
	t_img	food;
	t_img	player;
	t_img	wall;
}			t_img_set;

typedef struct s_game {
	void		*mlx;
	void		*win;
	t_img_set	img_set;
	int			width;
	int			height;
	char		**map;
	int			collectibles;
	int			player;
	int			exit;
	int			moves;
	int			player_x;
	int			player_y;
}				t_game;

void	ft_free(t_game *game);
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
int		ft_init_exit(t_game *game);
int		ft_init_floor(t_game *game);
int		ft_init_food(t_game *game);
int		ft_init_player(t_game *game);
int		ft_init_wall(t_game *game);
int		ft_init_images(t_game *game, char **error_msg);
void	ft_draw_map(t_game game);
void	ft_move_right(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
int		ft_key_press(int keycode, t_game *game);
int		ft_close(t_game *game);

#endif