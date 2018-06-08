//
// Created by Dmytro OMELCHENKO on 6/8/18.
//

#include "../fractol.h"

static void	ft_move_hook(int key, t_env *env)
{
	int		k;

	k = 50;
	if (key == ARR_LEFT)
		env->center_x -= k;
	else if (key == ARR_UP)
		env->center_y -= k;
	else if (key == ARR_RIGHT)
		env->center_x += k;
	else if (key == ARR_DOWN)
		env->center_y += k;
}

int			ft_key_hook(int key, void *p)
{
	t_env	*env;

	if (key == ESC)
		exit(0);
	env = (t_env *)p;
	ft_move_hook(key, env);
	ft_render(env);
	return (0);
}
