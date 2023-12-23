/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:19:21 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/23 17:00:09 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx_opengl_20191021/mlx.h"
# include <stdbool.h> 
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_complex
{
	double	real;
	double	i;
}	t_complex;
//variables necesarias para crear la imagen
typedef struct s_data
{
	void	*image; //puntero a la imagen
	char	*adress; //dirección de la imagen
	int		bbp; //bites por pixel
	int		line_len; //tamaño
	int		endian; //tamaño, aparentemente useless en macos
}	t_data;

typedef struct s_fractol
{
	void	*ptr_mlx; //iniciar la mlx
	void	*open_w;  //abrir una ventana
	int		keep_open;//mantener la ventana
	t_data	*image;   //crear una imagen
}	t_fractol;

//Parsing errors
void	iferror(bool iferror, int value, char *str);
int		ft_strncmp(char	*str1, char *str2, int size);
int		ft_atof(char	*str);
#endif