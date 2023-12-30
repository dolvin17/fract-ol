/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:19:21 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/30 22:19:39 by dolvin17         ###   ########.fr       */
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
# include <math.h>

# define MOUSE_DOWN			4
# define MOUSE_UP			5
# define KEY_PLUS			30
# define KEY_MINUS			44
# define KEY_SPACE			49
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
	double	move_x;
	double	move_y;
	double	zoom;
	double	julia_real;
	double	julia_i;
	int		color;

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

# define MSG_ERROR "\n\033[1;31mError:\033[0m Se espera:\n\
	\t\"./fractol mandelbrot\" ó\n\
	\t\"./fractol multibrot\" ó\n\
	\t\"./fractol julia <1>\" ó\n\
	\t\"./fractol julia <2>\" ó\n\
	\t\"./fractol julia <3>\" ó\n\
	\t\"./fractol julia <4>\"\n\n"

//Parsing errors
void		iferror(bool iferror, char *str);
int			ft_strncmp(char	*str1, char *str2, int size);
int			ft_atoi(char	*str);
void		perror_exit(void);
//init struct
void		init_fractol(t_fractol *fractol);
// complex values needs to be scaled
double		scale(double value, double new_min, double new_max, double old_max);
//sum two complex numbers (Z + c)
t_complex	sum_complex(t_complex z1, t_complex z2);
//square complex value i^2 = -1
t_complex	square_z(t_complex z);
//cube complex value z^3
t_complex	cube_z(t_complex z);
//Renders fractal based on fractal type and settings
void		rendering_fractol(t_fractol *fractol);
//Hooking events as keyboard, mouse interactions
void		hook_events(t_fractol *fractol);
void		zoom_in(t_fractol	*fractol, double mouse_x, double mouse_y);
void		zoom_out(t_fractol	*fractol, double mouse_x, double mouse_y);
#endif