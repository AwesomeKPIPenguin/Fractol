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
	int		i;

	parg = (t_parg *)arg;
	x[0] = (parg->section % 4) * (WIN_X / (THREADS / 2)) - 1;
	y[0] = (parg->section / 4) * (WIN_Y / 2) - 1;
	x[1] = x[0] + WIN_X / (THREADS / 2);
	y[1] = y[0] + WIN_Y / 2;
	while (++x[0] < x[1])
		while (++y[0] < y[1])
			ft_pixel_put_image(parg->env,
				x[0] + WIN_X_CENTER, y[0] + WIN_Y_CENTER,
				parg->env->ft_iter(parg->env, x[0], y[0]));
	return (NULL);
}

void	ft_render(t_env *env)
{
	pthread_t	threads[THREADS];
	t_parg		pargs[THREADS];
	int			i;

	env->zoom = 300.0;
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
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
