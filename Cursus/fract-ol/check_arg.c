/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 08:22:14 by gfaviere          #+#    #+#             */
/*   Updated: 2021/06/15 13:22:33 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_mandelbrot(char *str)
{
	if (ft_strcmp("mandelbrot", str) == 0)
		return (1);
	return (0);
}

int	check_julia(char *str)
{
	if (ft_strcmp("julia", str) == 0)
		return (1);
	return (0);
}

int	check_black_hole(char *str)
{
	if (ft_strcmp("black_hole", str) == 0)
		return (1);
	return (0);
}

int	check_arg(char *arg)
{
	if (check_mandelbrot(arg))
		return (1);
	if (check_julia(arg))
		return (2);
	if (check_black_hole(arg))
		return (3);
	return (0);
}
