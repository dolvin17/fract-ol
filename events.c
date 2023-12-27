/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:21:22 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/26 19:36:51 by dolvin17         ###   ########.fr       */
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
	if (keycode == XK_Escape)
		close_handler(fractol);
	printf("%d", keycode);
	printf("%p", fractol->ptr_mlx);
	rendering_fractol(fractol);
	return (0);
}

void	hook_events(t_fractol *fractol)
{
	mlx_hook(fractol->open_w, KeyPress, 0L, key_control, fractol);
}
