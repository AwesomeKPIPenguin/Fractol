
#include "../fractol.h"

int		ft_usage()
{
	ft_putendl("Usage: ./fractol {mandelbrot/julia/...}");
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
		return(ft_usage());
	env = ft_envnew();
	if (!ft_strcmp(av[1], "mandelbrot"))
		env->ft_iter = ft_man_iter;
	else
		return (ft_usage());
	ft_render(env);
	mlx_key_hook(env->win, ft_key_hook, (void *)env);
	mlx_mouse_hook(env->win, ft_mouse_hook, (void *)env);
	mlx_loop(env->mlx);
	return (1);
}
