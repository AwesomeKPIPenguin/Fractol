/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:56:36 by domelche          #+#    #+#             */
/*   Updated: 2018/06/14 16:56:38 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int			ft_close_hook(int x, int y, void *a)
{
	(void)x;
	(void)y;
	(void)a;
	exit(EXIT_SUCCESS);
	return (1);
}

int			ft_mouse_move_hook(int x, int y, void *a)
{
	t_env	*env;

	env = (t_env *)a;
	env->option_x = x;
	env->option_y = y;
	ft_render(env);
	return (0);
}
