/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_fractol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:50:32 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/24 01:17:45 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*mlx_pixel_put function is very, very slow. This is because it tries
to push the pixel instantly to the window (without waiting for the frame to be entirely rendered). 
Because of this sole reason, we will have to buffer all of our pixels to a image, 
which we will then push to the window.*/
void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->adress + (y * img->line_len + x * (img->bbp / 8));
	*(unsigned int *)dst = color;
}

//fn to get set complex numbers
static	void	coordenates(int x, int	y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	//primera iteración
	z.real = 0.0;
	z.i = 0.0;
	//escala para entrar en el set
	c.real = scale(x, -2, 2, 0, WIDTH);
	c.i = scale(y, 2, -2, 0, HEIGHT);
	i = 0;
	//while n cantidad de iteraciones de Z, checking if point converge o diverge
	while (i < 42)
	{
		//z = z^2 + c
		z = sum_complex(square_z(z), c);
		//si diverge
		if ((z.real * z.real) + (z.i * z.i) > 4)
		{
			color = scale(i, BLACK, NEON_PINK, 0, 42);
			my_mlx_pixel_put(&fractol->image, x, y, color);
			return ;
		}
		++i;
	}
	//los puntos convergen
	my_mlx_pixel_put(&fractol->image, x, y, NEON_BLUE);
}
void	rendering_fractol(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			coordenates(x, y, fractol);
	}
	mlx_put_image_to_window(fractol->ptr_mlx, fractol->open_w, fractol->image.img_ptr, 0, 0);
	mlx_loop(fractol->ptr_mlx);
}