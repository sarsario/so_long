/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:29:19 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/18 10:02:19 by osarsari         ###   ########.fr       */
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

typedef struct s_game {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	**map;
	int		collectibles;
	int		player;
	int		exit;
	int		player_x;
	int		player_y;
}			t_game;

int		ft_error(t_game *game, char *str);
void	ft_array_free(char **array);
int		ft_array_len(char **array);
char	**ft_array_dup(char **array);
int		ft_array_join(char ***array, char *str);
int		ft_valid_line(char *line, char **error_msg);
int		ft_enough_elements(char **error_msg, t_game *game);
int		ft_valid_path(char **error_msg, t_game *game);
int		ft_valid_file(char *file, char **error_msg, t_game *game);

#endif