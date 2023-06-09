/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:29:19 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/05 20:09:21 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./MiniLibX/mlx.h"
# include "./Lib/libft.h"
# include <fcntl.h>
# include <stdio.h>
#include <errno.h>
# include <math.h>

# define MAX_BUFFER_SIZE 8192
# define MIN_BUFFER_SIZE 1
# define MAX_FD 1024
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

typedef struct s_file
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
}			t_file;

typedef struct s_coord {
	int	x;
	int	y;
}		t_coord;

// typedef struct s_map {
// 	char	**map;
// 	int		width;
// 	int		height;
// }			t_map;

typedef struct s_game {
	void		*mlx;
	void		*win;
	char		**map;
	int			width;
	int			height;
	t_coord		*player;
	int			collectibles;
	int			moves;
}				t_game;

char	*get_next_line(int fd);
char	*read_file(t_file *file);
char	*my_get_line(t_file *file);
int		check_newline(t_file *file);
int		get_file_index(int fd, t_file *files);
size_t	ft_strlen2(char *s);
void	ft_substr2(t_file *file, int start);
char	*ft_strdup2(char *s);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_join_free(char *s1, char *s2);
char	**create_map(int fd);
void	loop_map(t_game *game);
int		valid_extension(const char *file);
int		count_char(char **map, char c);
int		count_lines(char **map);
int		valid_map(char **map);
int		valid_char(char c);
int		valid_line(char *line);
int		rectangular_map(char **map);
int		walled_map(char **map);
void	null_game(t_game *game);
t_coord	*get_pos(char **map, char c);
t_coord	**get_collectibles(char **map);
t_coord	**free_ls_coord(t_coord **ls);
int		found_path(t_game *game, t_coord *start, t_coord *end);
int		**init_visited(t_game *game);
int		**free_visited(int **visited, int height);

#endif