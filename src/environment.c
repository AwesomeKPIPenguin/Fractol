/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:56:17 by domelche          #+#    #+#             */
/*   Updated: 2018/06/14 16:59:39 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_env	*ft_envnew(void)
{
	t_env	*env;

	env = (t_env *)ft_smemalloc(sizeof(t_env), "ft_envnew");
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx,
		WIN_X, WIN_Y, "Fractol - domelche");
	env->img = ft_imgnew(env);
	env->center_x = WIN_X_CENTER;
	env->center_y = WIN_Y_CENTER;
	env->zoom = 300.0;
	env->i_max = 25;
	env->option_x = env->center_x;
	env->option_y = env->center_y;
	return (env);
}
