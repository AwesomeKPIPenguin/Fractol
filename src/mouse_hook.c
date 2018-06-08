//
// Created by Dmytro OMELCHENKO on 6/8/18.
//

#include "../fractol.h"

int			ft_mouse_hook(int mouse, int x, int y, void *p)
{
	t_env		*env;
	long double	zoom;
	long long	move_x;
	long long	move_y;

	if (mouse != 4 && mouse != 5)
		return (0);
	env = (t_env *)p;
	if (mouse == 4)
		zoom = 1.3;
	else
		zoom = 1.0 / 1.3;
	move_x = (long long)((double)(x - env->center_x) * (1 - zoom));
	move_y = (long long)((double)(y - env->center_y) * (1 - zoom));
	env->zoom *= zoom;
	ft_render(env);
	env->center_x += move_x;
	env->center_y += move_y;
	ft_render(env);
	return (x + y);
}
