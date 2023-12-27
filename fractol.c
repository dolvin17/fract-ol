/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:47:47 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/27 17:50:07 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_util_data(t_fractol *fractol)
{
	fractol->iterations = 42;
	fractol->hypotenuse = 4;
	fractol->move_x = 0.0;
	fractol->move_y = 0.0;
	fractol->zoom = 1.0;
}
// funcion para inicializar el struct
void	init_fractol(t_fractol *fractol)
{
	fractol->ptr_mlx = mlx_init();
	if (fractol->ptr_mlx == NULL)
		printf("Malloc failed");
	fractol->open_w = mlx_new_window(fractol->ptr_mlx, WIDTH, HEIGHT, fractol->name);
	if (fractol->open_w == NULL)
		printf("creating window failed");
	fractol->image.img_ptr = mlx_new_image(fractol->ptr_mlx, WIDTH, HEIGHT);
	if (fractol->image.img_ptr == NULL)
	{
		mlx_destroy_window(fractol->ptr_mlx, fractol->open_w);
		printf("failed accesing the image");
	}
	fractol->image.adress = mlx_get_data_addr(fractol->image.img_ptr, &fractol->image.bbp, &fractol->image.line_len, &fractol->image.endian);
	//pdte inicializar las variables de la imagen
	//bpp, line_len, endian
	//datos del fractal
	init_util_data(fractol);
	hook_events(fractol);
}
