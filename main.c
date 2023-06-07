/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:02:20 by osarsari          #+#    #+#             */
/*   Updated: 2023/06/07 19:55:57 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	ft_border(&img, 800, 600, 0x00FFFFFF);
	ft_border(&img, 799, 599, rgba_to_hex(156, 53, 219, 0));
	ft_border(&img, 798, 598, 0x00FFFFFF);
	ft_border(&img, 797, 597, rgba_to_hex(156, 53, 219, 0));
	ft_border(&img, 796, 596, 0x00FFFFFF);
	ft_border(&img, 795, 595, rgba_to_hex(156, 53, 219, 0));
	ft_circle(&img, 294, rgba_to_hex(39, 202, 245, 0));
	ft_circle(&img, 293, rgba_to_hex(20, 130, 161, 0));
	ft_circle(&img, 292, rgba_to_hex(123, 207, 39, 0));
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
