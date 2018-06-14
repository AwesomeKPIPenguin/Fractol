/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:55:19 by domelche          #+#    #+#             */
/*   Updated: 2018/06/14 16:59:22 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		ft_bur_iter(t_env *env, t_ftl *ftl, long long x, long long y)
{
	int i;

	ftl->z_r = (long double)x / env->zoom;
	ftl->z_i = (long double)y / env->zoom;
	ftl->c_r = ftl->z_r;
	ftl->c_i = ftl->z_i;
	i = -1;
	while (++i < env->i_max)
	{
		if (ftl->z_r * ftl->z_r + ftl->z_i * ftl->z_i >= 4)
			break ;
		ftl->z_tmp = ftl->z_r * ftl->z_r - ftl->z_i * ftl->z_i + ftl->c_r;
		ftl->z_i = fabsl(2 * ftl->z_r * ftl->z_i) + ftl->c_i;
		ftl->z_r = ftl->z_tmp;
	}
	return (ft_getcolor((i == env->i_max) ? -1 : i, env->clr_mode));
}
