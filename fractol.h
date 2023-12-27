/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:19:21 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/27 17:49:48 by ghuertas         ###   ########.fr       */
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

# define KEY_PLUS			30
# define KEY_MINUS			44
# define KEY_ESC			53
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_DOWN			125
# define KEY_UP				126

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
	int		iterations;
	double	hypotenuse;
	double	move_x;
	double	move_y;
	double	zoom;
}	t_fractol;

# define WIDTH 800
# define HEIGHT 800
//colors for fractal
# define NEON_PINK 0xFF1493
# define NEON_GREEN 0x00FF00
# define NEON_BLUE 0x00FFFF
# define NEON_YELLOW 0xBBFF00
# define NEON_RED 0xAA0000
# define BLACK 0x000000
# define WHITE 0xFFFFFF

//Parsing errors
void		iferror(bool iferror, int value, char *str);
int			ft_strncmp(char	*str1, char *str2, int size);
int			ft_atof(char	*str);
//init struct
void		init_fractol(t_fractol *fractol);
// data
double		scale(double value, double new_min, double new_max, double old_min, double old_max);
//suma dos numeros complejos.
t_complex	sum_complex(t_complex z1, t_complex z2);
//cuadrado de un numero complejo. i^2 = -1
t_complex	square_z(t_complex z);
void		rendering_fractol(t_fractol *fractol);
//Hooking events
void	hook_events(t_fractol *fractol);
int		key_control(int keysym, t_fractol *fractol);
#endif