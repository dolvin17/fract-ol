/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:28:15 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/22 23:47:28 by dolvin17         ###   ########.fr       */
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

int	ft_atof(char	*str)
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
