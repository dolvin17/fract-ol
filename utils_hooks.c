/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:36:55 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/30 22:45:39 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_out(t_fractol	*fractol, double mouse_x, double mouse_y)
{
	fractol->zoom /= 1.05 * 0.5;
	fractol->move_x += mouse_x / (0.5 * WIDTH * fractol->zoom);
	fractol->move_y += mouse_y / (0.5 * HEIGHT * fractol->zoom);
}

void	zoom_in(t_fractol	*fractol, double mouse_x, double mouse_y)
{
	fractol->zoom *= 0.95 * 0.5;
	fractol->move_x -= mouse_x / (0.5 * WIDTH * fractol->zoom);
	fractol->move_y -= mouse_y / (0.5 * HEIGHT * fractol->zoom);
}
