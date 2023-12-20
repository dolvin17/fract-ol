/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:28:15 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/20 15:41:29 by dolvin17         ###   ########.fr       */
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
