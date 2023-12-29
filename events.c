/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:21:22 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/29 23:38:33 by dolvin17         ###   ########.fr       */
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
	printf("tecla %d\n", keycode);
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

void	zoom_out(t_fractol	*fractol, double mouse_x, double mouse_y)
{
	fractol->zoom *= 2.0;
	fractol->move_x += mouse_x / (0.5 * WIDTH * fractol->zoom);
	fractol->move_y += mouse_y / (0.5 * HEIGHT * fractol->zoom);
}
void	zoom_in(t_fractol	*fractol, double mouse_x, double mouse_y)
{
	fractol->zoom /= 2.0;
	fractol->move_x -= mouse_x / (0.5 * WIDTH * fractol->zoom);
	fractol->move_y -= mouse_y / (0.5 * HEIGHT * fractol->zoom);
}

int	mouse_control(int keycode, int x, int y, t_fractol *fractol)
{	
	double i;
	double real;

	real = (x - WIDTH / 2) / (0.5 * WIDTH * fractol->zoom) + fractol->move_x;
	i = (y - HEIGHT / 2) / (0.5 * HEIGHT * fractol->zoom) + fractol->move_y;
	printf("x posicion %d\n", x);
	printf("y posicion: %d\n", y);
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
}
