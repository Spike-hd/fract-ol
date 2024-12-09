/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:01:02 by spike             #+#    #+#             */
/*   Updated: 2024/12/09 23:59:07 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"


unsigned int	init_iterate_pixel(int x, int y, t_graph graph)
{
	t_pixel	pixel;
	double		zr;
	double		zi;
	int			z_total;

	pixel.x_graph = graph.min_real + ((double)x / graph.largeur)*(graph.max_real - graph.min_real);
	pixel.y_graph = graph.min_img + ((double)y / graph.hauteur)*(graph.max_img - graph.min_img);

	zr = pow(pixel.x_graph, 2) - pow(pixel.y_graph, 2); + pixel.x_graph;
	zi = 2 * pixel.x_graph * pixel.y_graph + pixel.y_graph;
}



int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	img;
	int		largeur = 800;
	int		hauteur = 600;
	t_graph	graph;

	// j'initialise les valeurs de mon graphique
	graph.max_img = 1;
	graph.min_img = -1;
	graph.max_real = 3;
	graph.min_real = -1;
	graph.largeur = largeur;
	graph.hauteur = hauteur;

	// Les valeurs pour parcourir la window
	int		x;
	int		y;
	char	*dst;

	// Initialisation de MiniLibX et création de la fenêtre
	mlx = mlx_init();
	win = mlx_new_window(mlx, largeur, hauteur, "FRACTAL");

	// Création de l'image
	img.img = mlx_new_image(mlx, largeur, hauteur);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	y = 0;
	while (y < hauteur)
	{
		x = 0;
		while (x < largeur)
		{
			dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
			*(unsigned int *)dst = init_iterate_pixel(x, y, graph);
			x++;
		}
		y++;
	}
    // Affichage de l'image dans la fenêtre
    mlx_put_image_to_window(mlx, win, img.img, 0, 0);

    // Boucle pour garder la fenêtre ouverte
    mlx_loop(mlx);
}
