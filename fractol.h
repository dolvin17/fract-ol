/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:19:21 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/23 22:24:23 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx_opengl_20191021/mlx.h"
# include <stdbool.h> 
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>


typedef struct s_complex
{
	double	real;
	double	i;
}	t_complex;
//variables necesarias para crear la imagen
typedef struct s_data
{
	void	*img_ptr;
	char	*adress;
	int		bbp;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_fractol
{
	char	*name;
	void	*ptr_mlx;
	void	*open_w;
	t_data	image;
}	t_fractol;

# define WIDTH 800
# define HEIGHT 800
//Parsing errors
void		iferror(bool iferror, int value, char *str);
int			ft_strncmp(char	*str1, char *str2, int size);
int			ft_atof(char	*str);
//init struct
void		init_fractol(t_fractol *fractol);
// data
double		scale(double value, double new_min, double new_max, double old_min, double old_max);
//suma dos numeros complejos.
t_complex	sum_complex(t_complex zx, t_complex zi);
//cuadrado de un numero complejo. i^2 = -1
t_complex	square_z(t_complex z);
#endif