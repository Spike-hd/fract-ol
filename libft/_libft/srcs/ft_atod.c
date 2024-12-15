/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spike <spike@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:45:05 by spike             #+#    #+#             */
/*   Updated: 2024/12/15 20:55:38 by spike            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	check_sign(char *str)
{
	int	sign;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
	}
	return (sign);
}

double	ft_atod(char *str)
{
	int		i;
	int		sign;
	double	nb;
	double	fnb;
	double	divisor;

	sign = check_sign(str);
	nb = (double)ft_atoi(str);
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	fnb = 0;
	divisor = 10;
	if (str[i] == '.')
	{
		i++;
		while (str[i] && ft_isdigit(str[i]))
		{
			fnb += (str[i] - '0') / divisor;
			divisor *= 10;
			i++;
		}
	}
	return (sign * (nb + fnb));
}
