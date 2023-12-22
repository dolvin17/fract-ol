/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:24:35 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/22 16:21:34 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(char	**real, char **imaginary)
{
	int	x;
	int	y;

	if (!*real || !*imaginary)
		return ;
	x = ft_atoi(*real);
	y = ft_atoi(*imaginary);
	printf("real: %d\n", x);
	printf("imaginay: %d\n", y);
	printf("hola, soy julia");
}

int	main(int argc, char **argv)
{
	t_complex	z;
	t_complex	c;
	int			i;
	double		temp;

	i = 0;
	if (argc <= 4)
	{
		if (argv[1] && ft_strncmp(argv[1], "julia", 5) == 0)
		{
			julia(&argv[2], &argv[3]);
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
	while (i < 10)
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
