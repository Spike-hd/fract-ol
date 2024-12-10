/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:52:35 by spike             #+#    #+#             */
/*   Updated: 2024/12/10 23:38:51 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

unsigned int	select_color(t_pixel pixel)
{
	double		zr;
	double		temp_zr;
	double		zi;
	int			i;

	zr = 0;
	zi = 0;
	i = 0;
	while (zr * zr + zi * zi < (double)4.0 && i < 300)
	{
		temp_zr = zr* zr - zi * zi + pixel.x_graph;
		zi = 2 * zr * zi + pixel.y_graph;
		zr = temp_zr;
		i++;
	}

	if (i == 300)
		return (0x000000);

	unsigned int red = (i * 1) % 256;
	unsigned int green = (i * 3) % 256;
	unsigned int blue = (i * 5) % 256;
	return (red << 16 | green << 8 | blue);
}

unsigned int	init_pixel_color(int x, int y, t_graph graph)
{
	t_pixel		pixel;

	graph.real_range = (graph.max_real - graph.min_real) / graph.zoom;
	graph.img_range = (graph.max_img - graph.min_img) / graph.zoom;

	graph.center_real = (graph.min_real + graph.max_real) / 2.0; // => pour centrer au milieu
	graph.center_img = (graph.min_img + graph.max_img) / 2.0;    // => same

	pixel.x_graph = graph.center_real - graph.real_range / 2 + ((double)x / graph.width) * graph.real_range;
	pixel.y_graph = graph.center_img - graph.img_range / 2 + ((double)y / graph.height) * graph.img_range;

	return (select_color(pixel));
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
