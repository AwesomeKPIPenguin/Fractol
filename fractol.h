/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domelche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 16:58:34 by domelche          #+#    #+#             */
/*   Updated: 2018/06/14 16:58:38 by domelche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <math.h>
# include <limits.h>
# include <pthread.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"

# define ESC			0X35
# define ARR_UP			0X7E
# define ARR_DOWN		0X7D
# define ARR_RIGHT		0X7C
# define ARR_LEFT		0X7B
# define R				0X0F
# define PLUS			0X45
# define MINUS			0X4E
# define C				0X08

# define MOTION_MASK	(1L << 6)
# define MOTION_NOTIFY	6
# define CLOSE_MASK		0L
# define CLOSE_NOTIFY	17

# define WIN_X			1000
# define WIN_Y			700
# define WIN_X_CENTER	(WIN_X / 2)
# define WIN_Y_CENTER	(WIN_Y / 2)

# define THREADS		8

# define BLACK			0X000000

typedef union		u_color
{
	int				val;
	unsigned char	argb[4];
}					t_color;

typedef struct		s_ftl
{
	long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
	long double		z_tmp;
}					t_ftl;

typedef struct		s_img
{
	void			*ptr;
	int				width;
	int				height;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	long double		zoom;
	int				i_max;
	int				clr_mode;
	int				(*ft_iter)(struct s_env *, t_ftl *, long long, long long);
	long long		center_x;
	long long		center_y;
	long long		option_x;
	long long		option_y;
}					t_env;

typedef struct		s_parg
{
	int				section;
	t_env			*env;
}					t_parg;

/*
**	image.c
*/

t_img				*ft_imgnew(t_env *env);
void				ft_pixel_put_image(t_env *env, int x, int y, int color);

/*
**	environment.c
*/

t_env				*ft_envnew();

/*
**	color.c
*/

int					ft_getcolor(long double i, int color_mode);

/*
**	render.c
*/

void				ft_render(t_env *env);

/*
**	mandelbrot.c
*/

int					ft_man_iter(t_env *env, t_ftl *ftl,
								long long x, long long y);

/*
**	julia.c
*/

int					ft_jul_iter(t_env *env, t_ftl *ftl,
								long long x, long long y);

/*
**	newton.c
*/

int					ft_new_iter(t_env *env, t_ftl *ftl,
								long long x, long long y);

/*
**	burning_ship.c
*/

int					ft_bur_iter(t_env *env, t_ftl *ftl,
								long long x, long long y);

/*
**	hook.c
*/

int					ft_mouse_move_hook(int x, int y, void *a);
int					ft_close_hook(int x, int y, void *a);

/*
**	key_hook.c
*/

int					ft_key_hook(int key, void *p);

/*
**	mouse_hook.c
*/

int					ft_mouse_hook(int mouse, int x, int y, void *p);

#endif
