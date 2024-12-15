/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:48:51 by spike             #+#    #+#             */
/*   Updated: 2024/12/15 21:41:05 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	wiki(void)
{
	ft_printf("\n========== WIKI FRACT-OL ==========\n\n");
	ft_printf("At runtime, you must specify a fractal to display. ");
	ft_printf("Additional optional parameters can also be provided :\n\n");
	ft_printf("./fract-ol <type> <options>\n\n");
	ft_printf("Mandelbrot, mandelbrot, or 1 : Mandelbrot fractal\n");
	ft_printf("Julia, julia, or 2 : Julia fractal\n\n");
	ft_printf("For the Julia fractal set (and only for this set), ");
	ft_printf("two additional parameters can be provided as calculation ");
	ft_printf("values.\nThese parameters correspond to a complex number that ");
	ft_printf("modifies the shape of the Julia fractal.\nThey must be ");
	ft_printf("fractional numbers ranging from -2.0 to 2.0.\nExample :\n\n");
	ft_printf("./fractol 2 0.285 -0.01\n\n");
	ft_printf("You can specify the intensity of the RGB color from 0 to 255");
	ft_printf("\nPutting a letter would be consider as a 0 for the intensity");
	ft_printf("\nfractal's appearance :\n\n./fractol 1 5 10 34\n\n");
	ft_printf("However, for the Julia set, the color option can only be ");
	ft_printf("used after specifying the calculation values :\n\n");
	ft_printf("./fractol Julia -0.4 0.6 45 50 22\n\n");
	ft_printf("========== FRACT-OL CONTROLS ==========\n\n");
	ft_printf("|------------------------|--------------------|\n");
	ft_printf("|      scroll wheel      |  Zoom in and out   |\n");
	ft_printf("|------------------------|--------------------|\n");
	ft_printf("| echap or close control |   Quit fract-ol    |\n");
	ft_printf("|------------------------|--------------------|\n\n");
	ft_printf("Exiting properly...");
}

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
