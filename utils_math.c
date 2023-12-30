/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:47:33 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/30 19:21:20 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double value, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * (value - 0) / (old_max - 0) + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	value;

	value.real = (z1.real + z2.real);
	value.i = (z1.i + z2.i);
	return (value);
}

//cuadrado de Z
// coordenada x = x^2 - y^2
// coordenada y = 2*x*y
t_complex	square_z(t_complex z)
{
	t_complex	value;

	value.real = pow(z.real, 2) - pow(z.i, 2);
	value.i = 2 * z.real * z.i;
	return (value);
}

//cubo de Z
// coordenada x = x^3 - 3 * x * y^2
// coordenada y = 3 * x^2 * y - y^3
t_complex	cube_z(t_complex z)
{
	t_complex	result;

	result.real = pow(z.real, 3) - 3 * z.real * pow(z.i, 2);
	result.i = 3 * pow(z.real, 2) * z.i - pow(z.i, 3);
	return (result);
}
