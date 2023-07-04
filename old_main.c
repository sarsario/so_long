/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:02:20 by osarsari          #+#    #+#             */
/*   Updated: 2023/07/04 10:59:19 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./MiniLibX/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
// #include <time.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		key_pressed;
	t_data	*data;
}			t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	rgba_to_hex(int r, int g, int b, float a)
{
	int	alpha;

	alpha = (int)(a * 255);
	return ((alpha << 24) | (r << 16) | (g << 8) | b);
}

void	ft_border(t_data *data, int length, int width, int color)
{
	int	start_x;
	int	start_y;

	start_x = 800 - length;
	while (start_x < length)
	{
		start_y = 600 - width;
		while (start_y < width)
		{
			if (start_x == 800 - length || start_x == length - 1
				|| start_y == 600 - width || start_y == width - 1)
				my_mlx_pixel_put(data, start_x, start_y, color);
			start_y++;
		}
		start_x++;
	}
}

void	ft_circle(t_data *data, int radius, int color)
{
	int	x;
	int	y;
	int	decision;

	x = radius;
	y = 0;
	decision = 1 - x;
	while (y <= x)
	{
		my_mlx_pixel_put(data, 400 + x, 300 + y, color);
		my_mlx_pixel_put(data, 400 + y, 300 + x, color);
        my_mlx_pixel_put(data, 400 - x, 300 + y, color);
        my_mlx_pixel_put(data, 400 - y, 300 + x, color);
        my_mlx_pixel_put(data, 400 + x, 300 - y, color);
        my_mlx_pixel_put(data, 400 + y, 300 - x, color);
        my_mlx_pixel_put(data, 400 - x, 300 - y, color);
        my_mlx_pixel_put(data, 400 - y, 300 - x, color);
		y++;
		if (decision <= 0)
			decision += 2 * y + 1;
		else
		{
			x--;
			decision += 2 * (y - x) + 1;
		}
	}
}

int	escape_quit(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	replace_img(int keycode, t_vars *vars)
{
	int		img_width;
	int		img_height;
	void	*new_img;

	if (keycode == 13)
	{
		new_img = mlx_xpm_file_to_image(vars->mlx, "./gift.xpm",
			&img_width, &img_height);
		printf("img_w: %i\nimg_h: %i\n", img_width, img_height);
		if (new_img)
		{
			mlx_destroy_image(vars->mlx, vars->data->img);
			vars->data->img = new_img;
			vars->data->addr = mlx_get_data_addr(vars->data->img,
				&vars->data->bits_per_pixel, &vars->data->line_length,
				&vars->data->endian);
				mlx_put_image_to_window(vars->mlx, vars->win, vars->data->img,
					0, 0);
		}
	}
	return (0);
}

int	handle_key_press(int keycode, t_vars *vars)
{
	if (keycode == 53)
		escape_quit(keycode, vars);
	else if ((keycode >= 0 && keycode <= 2) || keycode == 13)
		replace_img(keycode, vars);
	else
	{
		vars->key_pressed = keycode;
		printf("Keycode of pressed key: %i\n", keycode);
	}
	return (0);
}

int	mouse_pos(int x, int y)
{
	printf("(%i, %i)\n", x, y);
	return (0);
}

int	mouse_enter(int x, int y)
{
	printf("Hello!\n");
	return (mouse_pos(x, y));
}

int	mouse_leave(void)
{
	printf("See you soon!\n");
	return (0);
}

int	mouse_track(int x, int y)
{
	if (x >= 0 && x <= 800 && y >= 0 && y <= 600)
		return mouse_enter(x, y);
	else
		return mouse_leave();
}

// int	main(void)
// {
// 	t_data	img;
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 800, 600, "Hello world!");
// 	img.img = mlx_new_image(vars.mlx, 800, 600);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 			&img.endian);
// 	vars.data = &img;
// 	vars.key_pressed = 0;
// 	// ft_border(&img, 800, 600, 0x00FFFFFF);
// 	// ft_border(&img, 799, 599, rgba_to_hex(156, 53, 219, 0));
// 	// ft_circle(&img, 294, rgba_to_hex(39, 202, 245, 0));
// 	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
// 	mlx_key_hook(vars.win, handle_key_press, &vars);
// 	mlx_hook(vars.win, 6, 1L << 6, mouse_track, &vars);
// 	mlx_hook(vars.win, 17, 0, close_window, &vars);
// 	mlx_loop(vars.mlx);
// }
