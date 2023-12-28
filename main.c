/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:24:35 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/28 22:16:36 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(char	**real, char **imaginary, t_fractol *fractol)
{
	fractol->julia_real = ft_atof(*real);
	fractol->julia_i = ft_atof(*imaginary);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc <= 4)
	{
		if (argv[1] && ft_strncmp(argv[1], "julia", 5) == 0)
		{
			fractol.name = argv[1];
			julia(&argv[2], &argv[3], &fractol);
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
