/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:52:35 by spike             #+#    #+#             */
/*   Updated: 2024/12/15 21:28:25 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

unsigned int	color_julia(t_color color, t_pixel pixel, double c, double d)
{
	double		zr;
	double		temp_zr;
	double		zi;
	int			i;

	zr = pixel.x_graph;
	zi = pixel.y_graph;
	i = 0;
	while (zr * zr + zi * zi < (double)4 && i < 200)
	{
		temp_zr = zr * zr - zi * zi + c;
		zi = 2 * zr * zi + d;
		zr = temp_zr;
		i++;
	}
	if (i == 200)
		return (0x000000);
	return ((i * color.red) % 256 << 16
		| (i * color.green) % 256 << 8
		| (i * color.blue) % 256);
}

unsigned int	color_mandelbrot(t_color color, t_pixel pixel)
{
	double		zr;
	double		temp_zr;
	double		zi;
	int			i;

	zr = 0;
	zi = 0;
	i = 0;
	while (zr * zr + zi * zi < (double)4.0 && i < 200)
	{
		temp_zr = zr * zr - zi * zi + pixel.x_graph;
		zi = 2 * zr * zi + pixel.y_graph;
		zr = temp_zr;
		i++;
	}
	if (i == 200)
		return (0x000000);
	return ((i * color.red) % 256 << 16
		| (i * color.green) % 256 << 8
		| (i * color.blue) % 256);
}

unsigned int	init_pixel_color(int x, int y, t_data *img, int i)
{
	t_pixel	pixel;

	img->graph.real_range = (img->graph.max_real - img->graph.min_real)
		/ img->graph.zoom;
	img->graph.img_range = (img->graph.max_img - img->graph.min_img)
		/ img->graph.zoom;
	img->graph.center_real = (img->graph.min_real + img->graph.max_real) / 2.0;
	img->graph.center_img = (img->graph.min_img + img->graph.max_img) / 2.0;
	pixel.x_graph = img->graph.center_real - img->graph.real_range / 2
		+ ((double)x / img->graph.width) * img->graph.real_range;
	pixel.y_graph = img->graph.center_img - img->graph.img_range / 2
		+ ((double)y / img->graph.height) * img->graph.img_range;
	if (i == 1)
		return (color_mandelbrot(img->color, pixel));
	else
		return (color_julia(img->color, pixel,
				img->graph.julia_r, img->graph.julia_i));
}


void	init_graph_window(t_graph *graph)
{
	graph->min_real = MIN_R;
	graph->max_real = MAX_R;
	graph->min_img = MIN_I;
	graph->max_img = MAX_I;
	graph->zoom = 1.0;
	graph->width = WIDTH;
	graph->height = HEIGHT;
}

void	init_graph_window_julia(t_graph *graph, double c, double d)
{
	graph->min_real = MIN_R;
	graph->max_real = MAX_R;
	graph->min_img = MIN_I;
	graph->max_img = MAX_I;
	graph->zoom = 1.0;
	graph->width = WIDTH;
	graph->height = HEIGHT;
	graph->julia_r = c;
	graph->julia_i = d;
}
