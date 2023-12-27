/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:24:35 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/27 17:47:59 by ghuertas         ###   ########.fr       */
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
	t_fractol	fractol;

	if (argc <= 4)
	{
		if (argv[1] && ft_strncmp(argv[1], "julia", 5) == 0)
		{
			fractol.name = argv[1];
			julia(&argv[2], &argv[3]);
		}
		else if (argv[1] && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		{
			fractol.name = argv[1];
			init_fractol(&fractol);
			rendering_fractol(&fractol);
			mlx_loop(fractol.ptr_mlx);
			//mlx_hook(fractol.open_w, 02, 0L, key_control, &fractol);
			printf("fn mandelbrot"); // TODO
		}
		else
		{
			write(1, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
