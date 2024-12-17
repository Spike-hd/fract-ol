/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:01:02 by spike             #+#    #+#             */
/*   Updated: 2024/12/17 21:13:06 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	select_fractal(char *str)
{
	if (!ft_strncmp(str, "mandelbrot", ft_strlen(str)))
		return (1);
	if (!ft_strncmp(str, "Mandelbrot", ft_strlen(str)))
		return (1);
	if (!ft_strncmp(str, "1", ft_strlen(str)))
		return (1);
	if (!ft_strncmp(str, "julia", ft_strlen(str)))
		return (2);
	if (!ft_strncmp(str, "Julia", ft_strlen(str)))
		return (2);
	if (!ft_strncmp(str, "2", ft_strlen(str)))
		return (2);
	else
		return (0);
}

int	handle_color(t_data *img, int i, int j, int k)
{
	if (i > 255 || i < 0)
		return (1);
	if (j > 255 || j < 0)
		return (1);
	if (k > 255 || k < 0)
		return (1);
	img->color.red = i;
	img->color.green = j;
	img->color.blue = k;
	return (0);
}

int	handle_params_mandel(int ac, char **av, t_data *img)
{
	if (ac > 5)
		return (1);
	if (ac == 2)
		return (handle_color(img, 1, 3, 5));
	if (ac == 3)
		return (handle_color(img, ft_atoi(av[2]), 1, 1));
	if (ac == 4)
		return (handle_color(img, ft_atoi(av[2]), ft_atoi(av[3]), 1));
	if (ac == 5)
		return (handle_color(img, ft_atoi(av[2]),
				ft_atoi(av[3]), ft_atoi(av[4])));
	return (0);
}

int	handle_params_julia(int ac, char *av[], t_data *img)
{
	if (ac > 7)
		return (1);
	if (ac == 2 || ac == 4)
		return (handle_color(img, 1, 3, 5));
	if (ac == 5)
		return (handle_color(img, ft_atoi(av[4]), 1, 1));
	if (ac == 6)
		return (handle_color(img, ft_atoi(av[4]), ft_atoi(av[5]), 1));
	if (ac == 7)
		return (handle_color(img, ft_atoi(av[4]),
				ft_atoi(av[5]), ft_atoi(av[6])));
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	img;

	if (argc < 2)
		return (wiki(), 0);
	i = select_fractal(argv[1]);
	if (i < 0 || i > 2)
		return (wiki(), 0);
	if (i == 1)
	{
		if (handle_params_mandel(argc, argv, &img) == 1)
			return (wiki(), 0);
		mandelbrot(img);
	}
	if (i == 2 && argc == 2)
	{
		handle_params_julia(argc, argv, &img);
		julia(-0.8, 0.156, img);
	}
	else if (i == 2)
	{
		if (handle_params_julia(argc, argv, &img) == 1)
			return (wiki(), 0);
		julia(ft_atod(argv[2]), ft_atod(argv[3]), img);
	}
	else
		return (wiki(), 0);
}
