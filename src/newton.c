/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:58:06 by domelche          #+#    #+#             */
/*   Updated: 2018/06/14 16:58:07 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		ft_new_iter(t_env *env, t_ftl *ftl, long long x, long long y)
{
	int		i;

	ftl->z_r = (long double)x / env->zoom;
	ftl->z_i = (long double)y / env->zoom;
	ftl->c_r = 0.0;
	ftl->c_i = 0.0;
	i = -1;
	ftl->z_tmp = 1.0;
	while (ftl->z_tmp > 0.000001 && ++i < env->i_max)
	{
		ftl->c_r = ftl->z_r;
		ftl->c_i = ftl->z_i;
		ftl->z_tmp = (ftl->z_r * ftl->z_r + ftl->z_i * ftl->z_i) *
			(ftl->z_r * ftl->z_r + ftl->z_i * ftl->z_i);
		ftl->z_r = (2 * ftl->z_r * ftl->z_tmp + ftl->z_r * ftl->z_r -
			ftl->z_i * ftl->z_i) / (3.0 * ftl->z_tmp);
		ftl->z_i = (2 * ftl->z_i * (ftl->z_tmp - ftl->c_r)) /
			(3.0 * ftl->z_tmp);
		ftl->z_tmp = (ftl->z_r - ftl->c_r) * (ftl->z_r - ftl->c_r) +
			(ftl->z_i - ftl->c_i) * (ftl->z_i - ftl->c_i);
	}
	return (ft_getcolor((i == env->i_max) ? -1 : i, env->clr_mode));
}
