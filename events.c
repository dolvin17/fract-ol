/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:21:22 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/30 22:18:00 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->ptr_mlx, fractol->image.img_ptr);
	mlx_destroy_window(fractol->ptr_mlx, fractol->open_w);
	exit(EXIT_SUCCESS);
}

static	int	key_control(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ESC)
		close_handler(fractol);
	else if (keycode == KEY_UP)
		fractol->move_y -= 0.5 * (fractol->zoom);
	else if (keycode == KEY_DOWN)
		fractol->move_y += 0.5 * (fractol->zoom);
	else if (keycode == KEY_LEFT)
		fractol->move_x += 0.5 * (fractol->zoom);
	else if (keycode == KEY_RIGHT)
		fractol->move_x -= 0.5 * (fractol->zoom);
	else if (keycode == KEY_PLUS)
		fractol->iterations += 10;
	else if (keycode == KEY_MINUS)
		fractol->iterations -= 10;
	else if (keycode == KEY_SPACE)
	{
		if (fractol->color == NEON_RED)
			fractol->color = NEON_GREEN;
		else if (fractol->color == NEON_GREEN)
			fractol->color = BLACK;
		else
			fractol->color = NEON_RED;
	}
	rendering_fractol(fractol);
	return (0);
}

static	int	mouse_control(int keycode, int x, int y, t_fractol *fractol)
{	
	double	i;
	double	real;

	real = x / WIDTH;
	i = y / HEIGHT;
	if (keycode == MOUSE_UP)
		zoom_in(fractol, real, i);
	else if (keycode == MOUSE_DOWN)
		zoom_out(fractol, real, i);
	rendering_fractol(fractol);
	return (0);
}

void	hook_events(t_fractol *fractol)
{
	mlx_hook(fractol->open_w, 02, 0L, key_control, fractol);
	mlx_hook(fractol->open_w, 04, 0L, mouse_control, fractol);
	mlx_hook(fractol->open_w, 17, 0L, close_handler, fractol);
}
