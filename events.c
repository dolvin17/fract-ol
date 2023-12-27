/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:21:22 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/27 17:57:23 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->ptr_mlx, fractol->image.img_ptr);
	mlx_destroy_window(fractol->ptr_mlx, fractol->open_w);
	exit(EXIT_SUCCESS);
}

int	key_control(int keycode, t_fractol *fractol)
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
	rendering_fractol(fractol);
	return (0);
}

void	hook_events(t_fractol *fractol)
{
	mlx_hook(fractol->open_w, 02, 0L, key_control, fractol);  
}
