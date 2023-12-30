/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_fractol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:50:32 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/30 01:34:27 by dolvin17         ###   ########.fr       */
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

void	mandelbrot_or_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (!(ft_strncmp(fractol->name, "julia", 5)))
	{
		c->real = fractol->julia_real;
		c->i = fractol->julia_i;
	}
	else
	{
		c->real = z->real;
		c->i = z->i;
	}
}

//fn to get set complex numbers
static	void	coordenates(int x, int	y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;
	//1 iteracion
	z.real = (scale(x, -2, 2, 0, WIDTH) * fractol->zoom) + fractol->move_x;
	z.i = (scale(y, 2, -2, 0, HEIGHT) * fractol->zoom) + fractol->move_y;
	i = 0;
	mandelbrot_or_julia(&z, &c, fractol);
	//while n cantidad de iteraciones de Z, checking if point converge o diverge
	while (i < fractol->iterations)
	{
		//z = z^2 + c
		z = sum_complex(square_z(z), c);
		//si diverge
		if (hypotenuse(z) > 2)
		{
			color = scale(i, NEON_YELLOW, NEON_PINK, 0, fractol->iterations);
			my_mlx_pixel_put(&fractol->image, x, y, color);
			return ;
		}
		++i;
	}
	//los puntos convergen
    my_mlx_pixel_put(&fractol->image, x, y, NEON_RED);
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
}