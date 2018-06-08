//
// Created by Dmytro OMELCHENKO on 6/8/18.
//

#include "../fractol.h"

int			ft_mouse_hook(int mouse, int x, int y, void *p)
{
	t_env	*env;


	env = (t_env *)p;
	if (mouse == 4)
		env->zoom *= 1.3;
	else if (mouse == 5)
		env->zoom /= 1.3;
	ft_render(env);
	return (x + y);
}
