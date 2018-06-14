/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:57:23 by domelche          #+#    #+#             */
/*   Updated: 2018/06/14 17:00:43 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		ft_usage(void)
{
	ft_putendl("Usage: ./fractol { mandelbrot / julia / newton / ship }");
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
		return (ft_usage());
	env = ft_envnew();
	if (!ft_strcmp(av[1], "mandelbrot"))
		env->ft_iter = ft_man_iter;
	else if (!ft_strcmp(av[1], "julia"))
		env->ft_iter = ft_jul_iter;
	else if (!ft_strcmp(av[1], "newton"))
		env->ft_iter = ft_new_iter;
	else if (!ft_strcmp(av[1], "ship"))
		env->ft_iter = ft_bur_iter;
	else
		return (ft_usage());
	ft_render(env);
	mlx_key_hook(env->win, ft_key_hook, (void *)env);
	mlx_mouse_hook(env->win, ft_mouse_hook, (void *)env);
	mlx_hook(env->win, MOTION_NOTIFY, MOTION_MASK,
		ft_mouse_move_hook, (void *)env);
	mlx_hook(env->win, CLOSE_NOTIFY, CLOSE_MASK,
		ft_close_hook, (void *)env);
	mlx_loop(env->mlx);
	return (1);
}
