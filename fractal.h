/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hduflos <hduflos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:25:46 by spike             #+#    #+#             */
/*   Updated: 2024/12/11 15:38:52 by hduflos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

#include "minilibx/mlx.h"
#include "libft/ft_printf.h"
#include <stdlib.h>
#include <math.h>

# define ESC_KEY 53 // 65307 linux
# define HEIGHT 720
# define WIDTH 1280
# define MIN_R -2.0
# define MAX_R 2.0
# define MIN_I -1.0
# define MAX_I 1.0

typedef struct	s_graph
{
	double	min_img;
	double	max_img;
	double	min_real;
	double	max_real;
	double	real_range;
	double	img_range;
	double	center_real;
	double	center_img;
	double	zoom;
	double	julia_r;
	double	julia_i;
	int		width;
	int		height;

}				t_graph;

typedef struct	s_pixel
{
	double	x_graph;
	double	y_graph;
}				t_pixel;

typedef struct	s_data {
	void	*img;
	void	*win;
	void	*mlx;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_graph	graph;
}				t_data;

//			----Mandelbrot----
int				mandelbrot(void);
void			print_pixels(t_data *img, t_graph *graph, int i);
unsigned int	init_pixel_color(int x, int y, t_graph graph, int i);
void			init_graph_window(t_graph *graph);

//			----Julia----
void			init_graph_window_julia(t_graph *graph, double c, double d);
int				julia(double c, double d);

//			----ERROR-----
int				handle_keys(int keycode, void *param);
int				close_window(t_data *img);

int				handle_mouse(int button, int x, int y, t_data *img);

#endif
