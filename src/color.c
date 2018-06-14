/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:55:45 by domelche          #+#    #+#             */
/*   Updated: 2018/06/14 17:01:01 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		ft_getcolor(long double i, int color_mode)
{
	t_color	color;

	if (i == -1)
		return (BLACK);
	color.argb[3] = 0;
	if (!color_mode)
	{
		color.argb[2] = (unsigned char)(sinl(0.01 * i + 1) * 127.5 + 127.5);
		color.argb[1] = (unsigned char)(sinl(0.013 * i + 2) * 127.5 + 127.5);
		color.argb[0] = (unsigned char)(sinl(0.016 * i + 4) * 127.5 + 127.5);
	}
	else if (color_mode == 1)
	{
		color.argb[2] = (unsigned char)(sinl(0.01 * i + 1) * 127.5 + 127.5);
		color.argb[1] = (unsigned char)(sinl(0.015 * i + 1) * 127.5 + 127.5);
		color.argb[0] = (unsigned char)(sinl(0.02 * i + 1) * 127.5 + 127.5);
	}
	else
	{
		color.argb[2] = (unsigned char)(sinl(0.01 * i + 4) * 127.5 + 127.5);
		color.argb[1] = (unsigned char)(sinl(0.005 * i + 2) * 127.5 + 127.5);
		color.argb[0] = (unsigned char)(sinl(0.04 * i + 3) * 127.5 + 127.5);
	}
	return (color.val);
}
