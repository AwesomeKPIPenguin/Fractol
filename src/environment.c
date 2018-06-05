
#include "../fractol.h"

t_env	*ft_envnew()
{
	t_env	*env;

	env = (t_env *)ft_smemalloc(sizeof(t_env), "ft_envnew");
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx,
		WIN_X, WIN_Y, "Fractol - domelche");
	env->img = ft_imgnew(env);
	return (env);
}
