/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:25:46 by spike             #+#    #+#             */
/*   Updated: 2024/12/09 23:44:53 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

#include "minilibx/mlx.h"

typedef struct	s_graph
{
	double	min_img;
	double	max_img;
	double	min_real;
	double	max_real;
	int		largeur;
	int		hauteur;

}				t_graph;

typedef struct	s_pixel
{
	double	x_graph;
	double	y_graph;
}				t_pixel;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif
