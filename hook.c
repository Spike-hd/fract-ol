/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:48:51 by spike             #+#    #+#             */
/*   Updated: 2024/12/15 10:12:26 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	close_window(t_data *img)
{
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->win);
	exit(0);
}

int	handle_keys(int keycode, void *param)
{
	t_data	*img;

	img = (t_data *)param;
	if (keycode == ESC_KEY)
		close_window(img);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	if (button == 4)
		img->graph.zoom *= 1.1;
	else if (button == 5)
		img->graph.zoom /= 1.1;
	mlx_clear_window(img->mlx, img->win);
	print_pixels(img, &img->graph, img->fractal);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}
