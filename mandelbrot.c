/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:01:02 by spike             #+#    #+#             */
/*   Updated: 2024/12/10 23:11:18 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	print_pixels(t_data *img, t_graph *graph)
{
	int		x;
	int		y;
	char	*dst;

	y = 0;
	while (y < graph->height)
	{
		x = 0;
		while (x < graph->width)
		{
			dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
			*(unsigned int *)dst = init_pixel_color(x, y, *graph);
			x++;
		}
		y++;
	}
}

int	mandelbrot(void)
{
	t_data	img;

	// init graph and window values
	init_graph_window(&img.graph);

	// Initialisation de MiniLibX et création de la fenêtre
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.graph.width, img.graph.height, "Mandelbrot");

	// Création de l'image
	img.img = mlx_new_image(img.mlx, img.graph.width, img.graph.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	print_pixels(&img, &img.graph);
	mlx_hook(img.win, 2, 0, handle_keys, &img); // => handle juste l'esc
	mlx_hook(img.win, 17, 0, close_window, &img); // => same avec la croix
	mlx_mouse_hook(img.win, handle_mouse, &img);

    // Affichage de l'image dans la fenêtre
    mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);

    // Boucle pour garder la fenêtre ouverte
    mlx_loop(img.mlx);
	return (0);
}
