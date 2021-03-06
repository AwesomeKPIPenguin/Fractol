/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:56:45 by domelche          #+#    #+#             */
/*   Updated: 2018/06/14 16:56:46 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_img	*ft_imgnew(t_env *env)
{
	t_img	*img;

	img = (t_img *)ft_smemalloc(sizeof(t_img), "ft_imgnew [for img]");
	img->ptr = mlx_new_image(env->mlx, WIN_X, WIN_Y);
	img->data = mlx_get_data_addr(img->ptr, &(img->bpp),
		&(img->size_line), &(img->endian));
	img->bpp /= 8;
	return (img);
}

void	ft_pixel_put_image(t_env *env, int x, int y, int colour)
{
	if (x < 0 || x >= WIN_X || y < 0 || y >= WIN_Y)
		return ;
	*(int *)(env->img->data + (y * WIN_X + x) * env->img->bpp) =
		mlx_get_color_value(env->mlx, colour);
}
