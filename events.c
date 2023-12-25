/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:21:22 by dolvin17          #+#    #+#             */
/*   Updated: 2023/12/25 22:13:32 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	key_control(int keysym, t_fractol *fractol)
{
	printf("%d", keysym);
	printf("%p", fractol);
	return (0);
}

void	hook_events(t_fractol *fractol)
{
	mlx_hook(fractol->open_w, KeyPress, KeyPressMask, key_control, fractol);
}
