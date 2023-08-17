/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:29:19 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/17 16:18:43 by osarsari         ###   ########.fr       */
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

void	ft_free(t_game *game);
int		ft_valid_file(char *file, char **error_msg, t_game *game);
int		ft_error(t_game *game, char *str);
int		ft_enough_elements(char **error_msg, t_game *game);
int		ft_valid_path(char **error_msg, t_game *game);

#endif