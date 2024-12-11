/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hduflos <hduflos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:01:02 by spike             #+#    #+#             */
/*   Updated: 2024/12/11 15:39:06 by hduflos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"


void	wiki(void)
{
	ft_printf("\n========== WIKI FRACT-OL ==========\n\n");
	ft_printf("At runtime, you must specify a fractal to display. ");
	ft_printf("Additional optional parameters can also be provided :\n\n");
	ft_printf("./fract-ol <type> <options>\n\n");
	ft_printf(" - M, m, or 1 : Mandelbrot fractal\n");
	ft_printf(" - J, j, or 2 : Julia fractal\n\n");
	ft_printf("For the Julia fractal set (and only for this set), ");
	ft_printf("two additional parameters can be provided as calculation ");
	ft_printf("values. These parameters correspond to a complex number that ");
	ft_printf("modifies the shape of the Julia fractal. They must be ");
	ft_printf("fractional numbers ranging from -2.0 to 2.0. Example :\n\n");
	ft_printf("./fractol J 0.285 -0.01\n\n");
	ft_printf("You can also specify a hexadecimal color to customize the ");
	ft_printf("fractal's appearance :\n\n");
	ft_printf("./fractol M 00CCFF\n\n");
	ft_printf("However, for the Julia set, the color option can only be ");
	ft_printf("used after specifying the calculation values :\n\n");
	ft_printf("./fractol J -0.4 0.6 65CD87\n\n");
	ft_printf("========== FRACT-OL CONTROLS ==========\n\n");
	ft_printf("|------------------------|--------------------|\n");
	ft_printf("|      scroll wheel      |  Zoom in and out   |\n");
	ft_printf("|------------------------|--------------------|\n");
	ft_printf("| echap or close control |   Quit fract-ol    |\n");
	ft_printf("|------------------------|--------------------|\n\n");
	ft_printf("Exiting properly...");
}

int	handle_args(char c) // a modifier
{
	if (c == 'M' || c == 'm' || c == '1')
		mandelbrot();
	else if (c == 'J' || c == 'j' || c == '2')
		mandelbrot();
	else
		wiki();
 }

int	main(int argc, char *argv[])
{
	int	i;

	if (argc < 2)
		return(wiki(), 0);

	i = select_fractal(argv[1]); // a modifier
	if (i < 0 || (i == 1 && argc > 2))
		return(wiki(), 0);
	if (i == 1)
		return(wiki(), 0);rot();
	if (i == 2 && argc == 2)
		julia(c + di); // => mettre les valeurs de bases
	else if (i == 2 && argc == 4)
		julia(ft_atod(argv[2]), ft_atod(argv[3]));
	else
		return(wiki(), 0);
}

double	ft_atod(char *str)
{
	int		i;
	int		nb;
	int		res;
	int		fnb;
	double	final;

	nb = ft_atoi(str);
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	res = 1;
	while (str[i] && str[i] == '0')
	{
		res *= 10;
		i++;
	}
	fnb = 0.0;
	while (str[i] && ft_isdigit(str[i]))
	{
		fnb = 10 * fnb + (str[i] + '0');
		i++;
	}
	final = nb + (1 / (res*fnb));
	return (final);
}
