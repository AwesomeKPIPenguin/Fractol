//
// Created by Dimon on 09.06.2018.
//

#include "../fractol.h"

int			ft_mouse_move_hook(int x, int y, void *a)
{
	t_env	*env;

	env = (t_env *)a;
	env->option_x = x;
	env->option_y = y;
	ft_render(env);
	return (0);
}
