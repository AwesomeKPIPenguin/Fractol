/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:57:03 by domelche          #+#    #+#             */
/*   Updated: 2018/06/14 16:57:05 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		ft_jul_iter(t_env *env, t_ftl *ftl, long long x, long long y)
{
	int		i;

	ftl->z_r = (long double)x / env->zoom;
	ftl->z_i = (long double)y / env->zoom;
	i = -1;
	while (++i < env->i_max)
	{
		ftl->z_tmp = ftl->z_r;
		ftl->z_r = ftl->z_r * ftl->z_r - ftl->z_i * ftl->z_i - 0.8 +
			(0.6 / ((double)env->option_x / (double)WIN_X));
		ftl->z_i = 2 * ftl->z_i * ftl->z_tmp + 0.27015 /
			((double)env->option_y / (double)WIN_Y);
		if (ftl->z_r * ftl->z_r + ftl->z_i * ftl->z_i >= 4)
			break ;
	}
	return (ft_getcolor((i == env->i_max) ? -1 : i, env->clr_mode));
}
