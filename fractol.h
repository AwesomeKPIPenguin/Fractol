
#ifndef FRACTOL_H

# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <limits.h>
# include <pthread.h>
# include "libft/libft.h"

# define ESC			0X35
# define ARR_UP			0X7E
# define ARR_DOWN		0X7D
# define ARR_RIGHT		0X7C
# define ARR_LEFT		0X7B
# define ARR_LESS		0X2B
# define ARR_MORE		0X2F
# define W				0X0D
# define A				0X00
# define S				0X01
# define D				0X02
# define PLUS			0X45
# define MINUS			0X4E
# define C				0X08

# define WIN_X			1000
# define WIN_Y			700
# define WIN_X_CENTER	(WIN_X / 2)
# define WIN_Y_CENTER	(WIN_Y / 2)

# define THREADS		8

# define BLACK			0X000000
# define WHITE			0XFFFFFF
# define DARK_RED		0X800000
# define RED			0XFF0000
# define LIGHT_RED		0XFF8080
# define RED_GREEN		0XFFFF00
# define DARK_GREEN		0X008000
# define GREEN			0X00FF00
# define LIGHT_GREEN	0X80FF80
# define GREEN_BLUE 	0X00FFFF
# define DARK_BLUE		0X000080
# define BLUE			0X0000FF
# define LIGHT_BLUE		0X8080FF
# define RED_BLUE		0XFF00FF

typedef struct	s_ftl
{
	long double	c_r;
	long double	c_i;
	long double	z_r;
	long double	z_i;
	long double	z_tmp;
}				t_ftl;

typedef struct	s_img
{
	void		*ptr;
	int			width;
	int			height;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		*img;
	long double	zoom;
	int			i_max;
	int			(*ft_iter)(struct s_env *env, int x, int y);

}				t_env;

typedef struct	s_parg
{
	int			section;
	t_env		*env;
}				t_parg;

/*
**	image.c
*/

t_img			*ft_imgnew(t_env *env);
void			ft_pixel_put_image(t_env *env, int x, int y, int colour);

/*
**	environment.c
*/

t_env			*ft_envnew();

/*
**	parg.c
*/

t_parg			ft_pargnew(t_env *env, int section);

/*
**	colour.c
*/

int				ft_getcolour(int i, int i_max);

/*
**	render.c
*/

void			ft_render(t_env *env);

/*
**	mandelbrot.c
*/

int				ft_man_iter(t_env *env, int x, int y);

#endif