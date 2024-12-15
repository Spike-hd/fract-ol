/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:01:02 by spike             #+#    #+#             */
/*   Updated: 2024/12/15 10:10:35 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	print_pixels(t_data *img, t_graph *graph, int i)
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
			dst = img->addr + (y * img->line_length + x * (img->bts_pxl / 8));
			*(unsigned int *)dst = init_pixel_color(x, y, *graph, i);
			x++;
		}
		y++;
	}
}

int	mandelbrot(void)
{
	t_data	img;

	img.fractal = 1;
	init_graph_window(&img.graph);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.graph.width, img.graph.height,
			"Mandelbrot");
	img.img = mlx_new_image(img.mlx, img.graph.width, img.graph.height);
	img.addr = mlx_get_data_addr(img.img, &img.bts_pxl,
			&img.line_length, &img.endian);
	print_pixels(&img, &img.graph, 1);
	mlx_hook(img.win, 2, 0, handle_keys, &img);
	mlx_hook(img.win, 17, 0, close_window, &img);
	mlx_mouse_hook(img.win, handle_mouse, &img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}

int	julia(double c, double d)
{
	t_data	img;

	img.fractal = 2;
	init_graph_window_julia(&img.graph, c, d);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.graph.width, img.graph.height,
			"Julia");
	img.img = mlx_new_image(img.mlx, img.graph.width, img.graph.height);
	img.addr = mlx_get_data_addr(img.img, &img.bts_pxl,
			&img.line_length, &img.endian);
	print_pixels(&img, &img.graph, 2);
	mlx_hook(img.win, 2, 0, handle_keys, &img);
	mlx_hook(img.win, 17, 0, close_window, &img);
	mlx_mouse_hook(img.win, handle_mouse, &img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}
