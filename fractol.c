/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:47:47 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/30 21:51:37 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	init_util_data(t_fractol *fractol)
{
	fractol->iterations = 70;
	fractol->move_x = 0.0;
	fractol->move_y = 0.0;
	fractol->zoom = 1.0;
	fractol->color = NEON_RED;
}

void	init_fractol(t_fractol *fractol)
{
	fractol->ptr_mlx = mlx_init();
	iferror(fractol->ptr_mlx == NULL, "mlx_init failed");
	fractol->open_w = mlx_new_window(fractol->ptr_mlx,
			WIDTH, HEIGHT, fractol->name);
	iferror(fractol->open_w == NULL, "mlx_new_window failed");
	fractol->image.img_ptr = mlx_new_image(fractol->ptr_mlx, WIDTH, HEIGHT);
	if (fractol->image.img_ptr == NULL)
	{
		mlx_destroy_window(fractol->ptr_mlx, fractol->open_w);
		perror("mlx_new_image failed");
		exit(EXIT_FAILURE);
	}
	fractol->image.adress = mlx_get_data_addr(fractol->image.img_ptr,
			&fractol->image.bbp, &fractol->image.line_len,
			&fractol->image.endian);
	init_util_data(fractol);
	hook_events(fractol);
}
