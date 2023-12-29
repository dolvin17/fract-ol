/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:24:35 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/29 22:20:01 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc <= 4)
	{
		if (argv[1] && ft_strncmp(argv[1], "julia", 5) == 0)
		{
			if (atoi(argv[2]) == 1)
			{
					fractol.julia_real = 0.285;
					fractol.julia_i = -0.01;
			}
			else if (atoi(argv[2]) == 2)
			{
					fractol.julia_real = 0.32;
					fractol.julia_i = 0.043;
			}
			else if (atoi(argv[2]) == 3)
			{
					fractol.julia_real = -0.624;
					fractol.julia_i = 0.435;
			}
			else if (atoi(argv[2]) == 4)
			{
					fractol.julia_real = -0.8;
					fractol.julia_i = 0.156;
			}
			else if (atoi(argv[2]) == 5)
			{
					fractol.julia_real = 0.285;
					fractol.julia_i = 0;
			}
			else if (atoi(argv[2]) == 6)
			{
					fractol.julia_real = -0.712;
					fractol.julia_i = 0.264;
			}
			else if (atoi(argv[2]) == 7)
			{
					fractol.julia_real = -0.755;
					fractol.julia_i = 0.15;
			}
				else if (atoi(argv[2]) == 8)
			{
					fractol.julia_real = -0.70176;
					fractol.julia_i = -0.3842;
			}
			
			fractol.name = argv[1];
			init_fractol(&fractol);
			rendering_fractol(&fractol);
			mlx_loop(fractol.ptr_mlx);
		}
		else if (argv[1] && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		{
			fractol.name = argv[1];
			init_fractol(&fractol);
			rendering_fractol(&fractol);
			mlx_loop(fractol.ptr_mlx);
		}
		else
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
