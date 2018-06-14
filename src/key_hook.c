/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:57:13 by domelche          #+#    #+#             */
/*   Updated: 2018/06/14 16:57:15 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	ft_imax_hook(int key, t_env *env)
{
	int		k;

	k = 5;
	if (key == PLUS)
		env->i_max += k;
	else if (key == MINUS)
		env->i_max -= (env->i_max < 5) ? 0 : k;
}

static void	ft_move_hook(int key, t_env *env)
{
	int		k;

	k = 50;
	if (key == ARR_LEFT)
		env->center_x += k;
	else if (key == ARR_UP)
		env->center_y += k;
	else if (key == ARR_RIGHT)
		env->center_x -= k;
	else if (key == ARR_DOWN)
		env->center_y -= k;
}

int			ft_key_hook(int key, void *p)
{
	t_env	*env;

	if (key == ESC)
		exit(0);
	env = (t_env *)p;
	ft_move_hook(key, env);
	ft_imax_hook(key, env);
	if (key == R)
	{
		env->zoom = 300.0;
		env->center_x = WIN_X_CENTER;
		env->center_y = WIN_Y_CENTER;
	}
	if (key == C)
		env->clr_mode += (env->clr_mode == 2) ? -2 : 1;
	ft_render(env);
	return (0);
}
