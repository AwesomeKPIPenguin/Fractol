//
// Created by Dimon on 06.06.2018.
//

#include "../fractol.h"

/*
**	x/y[0] - start point, iterator;
**	x/y[1] - end point;
*/

void	*ft_section_handle(void *arg)
{
	t_parg	*parg;
	int		x[2];
	int 	y[2];
	int		y_iter;

	parg = (t_parg *)arg;
	x[0] = (parg->section % 4) * (WIN_X / (THREADS / 2)) - 1;
	y[0] = (parg->section / 4) * (WIN_Y / 2) - 1;
	x[1] = x[0] + WIN_X / (THREADS / 2) + 1;
	y[1] = y[0] + WIN_Y / 2 + 1;
	while (++x[0] < x[1])
	{
		y_iter = y[0];
		while (++y_iter < y[1])
			ft_pixel_put_image(parg->env,
				x[0], y_iter, parg->env->ft_iter(parg->env,
					x[0] - WIN_X_CENTER - 250, y_iter - WIN_Y_CENTER));
	}
	return (NULL);
}

void	ft_render(t_env *env)
{
	pthread_t	threads[THREADS];
	t_parg		pargs[THREADS];
	int			i;

	env->zoom = 300.0;
	env->i_max = 100;

	i = -1;
	while (++i < THREADS)
	{
		pargs[i].section = i;
		pargs[i].env = env;
	}
	i = -1;
	while (++i < THREADS)
		pthread_create(&threads[i], NULL,
			ft_section_handle, (void *)&pargs[i]);
	i = -1;
	while (++i < THREADS)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(env->mlx, env->win, env->img->ptr, 0, 0);
}
