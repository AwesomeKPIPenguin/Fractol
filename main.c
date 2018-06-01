
#include <mlx.h>
#include <math.h>
#include <stdio.h>

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

int		main(void)
{
	void	*mlx;
	void	*win;
	int		n;
	double x = 0.0;
	double old_x = 0.0;
	double y = 0.0;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "Pisos");
	n = -1;
	for (int i = -500; i < 500; i++)
		for (int j = -500; j < 500; j++)
			ft_iter(mlx, win, i, j);
	mlx_loop(mlx);
	return (0);
}
