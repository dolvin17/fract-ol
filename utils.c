/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:28:15 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/29 22:58:32 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iferror(bool iferror, int value, char *str)
{
	if (iferror)
	{
		errno = value;
		perror(str);
		exit(EXIT_FAILURE);
	}
}

int	ft_strncmp(char	*str1, char *str2, int size)
{
	int	i;

	if (str1 == NULL || str2 == NULL || size == 0)
		return (0);
	i = 0;
	while (i <= size)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
//imput julia decimales
double	ft_atof(char	*str)
{
	int		sign;
	int		i;
	double	nbr;
	double	decimal;
	double	pos;

	sign = 1;
	pos = 1;
	nbr = 0;
	i = 0;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '.')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		pos = pos / 10;
		decimal = decimal + (str[i] - 48) * pos;
		i++;
	}
	return ((nbr + decimal) * sign);
}
//es necesario escalar los numeros
//para acceder a los valores que componen los fractales
double	scale(double value, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (value - old_min) / (old_max - old_min) + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	value;

	value.real = (z1.real + z2.real);
	value.i = (z1.i + z2.i);
	return (value);
}

//cuadrado de Z
// coordenada x = x^2 - y^2
// coordenada y = 2*x*y
t_complex	square_z(t_complex z)
{
	t_complex	value;

	value.real = pow(z.real, 2) - pow(z.i, 2);
	value.i = 2 * z.real * z.i;
	return (value);
}

double hypotenuse(t_complex z)
{
	return (hypot(z.real, z.i));
}