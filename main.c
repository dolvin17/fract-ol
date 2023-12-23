/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:24:35 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/23 16:54:01 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(char	**real, char **imaginary)
{
	double	x;
	double	y;

	if (!*real || !*imaginary)
		return ;
	x = ft_atof(*real);
	y = ft_atof(*imaginary);
	printf("real: 	  %3.6f\n", x);
	printf("imaginay: %3.6f\n", y);
	//printf("hola, soy julia");
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	int		mlx_loope;
	void	*img;
	t_complex	z;
	t_complex	c;
	int			i;
	double		temp;
	t_data imagen;
	int	pixel;
	int pitw;

	i = 0;
	if (argc <= 4)
	{
		if (argv[1] && ft_strncmp(argv[1], "julia", 5) == 0)
		{
			julia(&argv[2], &argv[3]);
			mlx = mlx_init();
			mlx_win = mlx_new_window(mlx, 800, 800, "pajarito");
			img = mlx_new_image(mlx, 400, 400);
			imagen.image = img;
			imagen.adress = mlx_get_data_addr(img, &imagen.bbp, &imagen.line_len, &imagen.endian);
			pixel = mlx_pixel_put(mlx, mlx_win, 400, 400, 0xFF0000);
			pitw = mlx_put_image_to_window(mlx, mlx_win, imagen.image, z.i, z.real);
			mlx_loope = mlx_loop(mlx);


			printf("%p", mlx);
			printf("%p", mlx_win);
			printf("%d", mlx_loope);
			printf("%p", img);
			printf("%d", pixel);
			printf("%d", pitw);
			
		}
		else if (argv[1] && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		{
			printf("fn mandelbrot");
		}
		else
			printf("parametros erroneos");
	}
	i = 0;
	z.real = 0;
	z.i = 0;
	c.real = 0.25;
	c.i = 0.4;
	while (i < 42)
	{
		// f(z) = z^2 + c
		temp = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = temp;

		z.real = z.real + c.real;
		z.i = z.i + c.i;
		printf("x = %f y = %f\n", z.real, z.i);
		i++;
	}
	return (0);
}
