/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:01:02 by spike             #+#    #+#             */
/*   Updated: 2024/12/15 10:27:25 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	wiki(void)
{
	ft_printf("\n========== WIKI FRACT-OL ==========\n\n");
	ft_printf("At runtime, you must specify a fractal to display. ");
	ft_printf("Additional optional parameters can also be provided :\n\n");
	ft_printf("./fract-ol <type> <options (for Julia)>\n\n");
	ft_printf("Mandelbrot, mandelbrot, or 1 : Mandelbrot fractal\n");
	ft_printf("Julia, julia, or 2 : Julia fractal\n\n");
	ft_printf("For the Julia fractal set (and only for this set), ");
	ft_printf("two additional parameters can be provided as calculation ");
	ft_printf("values.\nThese parameters correspond to a complex number that ");
	ft_printf("modifies the shape of the Julia fractal.\nThey must be ");
	ft_printf("fractional numbers ranging from -2.0 to 2.0. Example :\n\n");
	ft_printf("./fractol J 0.285 -0.01\n\n");
	ft_printf("========== FRACT-OL CONTROLS ==========\n\n");
	ft_printf("|------------------------|--------------------|\n");
	ft_printf("|      scroll wheel      |  Zoom in and out   |\n");
	ft_printf("|------------------------|--------------------|\n");
	ft_printf("| echap or close control |   Quit fract-ol    |\n");
	ft_printf("|------------------------|--------------------|\n\n");
	ft_printf("Exiting properly...");
}

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

int	main(int argc, char *argv[])
{
	int	i;

	if (argc < 2)
		return (wiki(), 0);
	i = select_fractal(argv[1]);
	if (i < 0 || (i == 1 && argc > 2))
		return (wiki(), 0);
	if (i == 1 && argc > 2)
		return (wiki(), 0);
	if (i == 1)
		mandelbrot();
	if (i == 2 && argc == 2)
		julia(-0.8, 0.156);
	else if (i == 2 && argc == 4)
		julia(ft_atod(argv[2]), ft_atod(argv[3]));
	else
		return (wiki(), 0);
}
