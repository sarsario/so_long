/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsari <osarsari@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:28:28 by osarsari          #+#    #+#             */
/*   Updated: 2023/08/21 18:26:04 by osarsari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_init_window(t_game *game, char **error_msg)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		*error_msg = "Error\nmlx_init() failed\n";
		return (0);
	}
	game->win = mlx_new_window(
			game->mlx,
			game->width * 32,
			game->height * 32,
			"so_long");
	if (!game->win)
	{
		*error_msg = "Error\nmlx_new_window() failed\n";
		return (0);
	}
	return (1);
}

int	ft_init_images(t_game *game, char **error_msg)
{
	if (!ft_init_exit(game) || !ft_init_floor(game) || !ft_init_food(game)
		|| !ft_init_player(game) || !ft_init_wall(game))
	{
		*error_msg = "Error\nmlx_xpm_file_to_image() failed\n";
		return (0);
	}
	return (1);
}

void	ft_draw_map(t_game game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game.height)
	{
		x = -1;
		while (++x < game.width)
		{
			mlx_put_image_to_window(game.mlx, game.win,
				game.img_set.floor.img, x * 32, y * 32);
			if (game.map[y][x] == '1')
				mlx_put_image_to_window(game.mlx, game.win,
					game.img_set.wall.img, x * 32, y * 32);
			else if (game.map[y][x] == 'C')
				mlx_put_image_to_window(game.mlx, game.win,
					game.img_set.food.img, x * 32 + 8, y * 32 + 8);
			else if (game.map[y][x] == 'E')
				mlx_put_image_to_window(game.mlx, game.win,
					game.img_set.exit.img, x * 32, y * 32);
		}
	}
	mlx_put_image_to_window(game.mlx, game.win,
		game.img_set.player.img, game.player_x * 32, game.player_y * 32 - 8);
}

// float scale_factor = 0.01;
// void scale_image(void *mlx_ptr, void *win_ptr, void *img_ptr, int orig_width,
// int orig_height) {
//     int new_width = orig_width * scale_factor;
//     int new_height = orig_height * scale_factor;
//     // Create a new image
//     void *scaled_img_ptr = mlx_new_image(mlx_ptr, new_width, new_height);
//     // Get the pixel data of the original image
// 	int bpp_original;
// 	int size_line_original;
// 	int endian_original;
//     char *orig_data = mlx_get_data_addr(img_ptr, &bpp_original,
// &size_line_original, &endian_original); // Get original image data
//     // Get the pixel data of the scaled image
// 	int bpp_scaled;
// 	int size_line_scaled;
// 	int endian_scaled;
//     char *scaled_data = mlx_get_data_addr(scaled_img_ptr, &bpp_scaled,
// &size_line_scaled, &endian_scaled); // Get scaled image data
//     // Perform nearest-neighbor scaling algorithm
//     for (int y = 0; y < new_height; y++) {
//         for (int x = 0; x < new_width; x++) {
//             int orig_x = x / scale_factor;
//             int orig_y = y / scale_factor;
//             // Copy the pixel from the original image to the scaled image
//             int orig_pixel_offset = (orig_y * orig_width + orig_x) * 4;
// Assuming 32-bit RGBA format
//             int scaled_pixel_offset = (y * new_width + x) * 4;
//             // Copy RGBA values
//             for (int channel = 0; channel < 4; channel++) {
//                 scaled_data[scaled_pixel_offset + channel] =
//	orig_data[orig_pixel_offset + channel];
//             }
//         }
//     }
//     // Display the scaled image
//     mlx_put_image_to_window(mlx_ptr, win_ptr, scaled_img_ptr, 0, 0);
// Display scaled image
// }
