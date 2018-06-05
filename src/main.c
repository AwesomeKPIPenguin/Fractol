
#include "../fractol.h"

void	ft_iter(void *mlx, void *win, int x, int y)
{
	double		i = -1.0;
	double		c_r = (double)x / 300.0;
	double		c_i = (double)y / 300.0;
	double		z_r = 0.0;
	double		z_i = 0.0;
	double		z_tmp;

	while (++i < 100)
	{
		if (pow(z_r, 2) + pow(z_i, 2) >= 4)
			return ;
		z_tmp = z_r;
		z_r = pow(z_r, 2) - pow(z_i, 2) + c_r;
		z_i = 2 * z_i * z_tmp + c_i;
	}
	mlx_pixel_put(mlx, win, x + 500, y + 500, 0xff0000);
}



int		ft_usage()
{
	ft_putstr("Usage: ./fractol mandelbrot/");
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac == 1)
		return(ft_usage());
	env = ft_envnew();

	mlx_loop(env->mlx);
	return (1);
}
