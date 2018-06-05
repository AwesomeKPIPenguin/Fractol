
#ifndef FRACTOL_H

# define FRACTOL_H

# include "minilibx_macos/mlx.h"
# include <math.h>
# include <limits.h>
# include "libft/libft.h"

# define ESC			0x35
# define ARR_UP			0x7E
# define ARR_DOWN		0x7D
# define ARR_RIGHT		0x7C
# define ARR_LEFT		0x7B
# define ARR_LESS		0x2B
# define ARR_MORE		0x2F
# define W				0x0D
# define A				0x00
# define S				0x01
# define D				0x02
# define PLUS			0x45
# define MINUS			0x4E
# define C				0x08

# define WIN_X			1000
# define WIN_Y			700

# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define DARK_RED		0x800000
# define RED			0xFF0000
# define LIGHT_RED		0xFF8080
# define RED_GREEN		0xFFFF00
# define DARK_GREEN		0x008000
# define GREEN			0x00FF00
# define LIGHT_GREEN	0x80FF80
# define GREEN_BLUE 	0x00FFFF
# define DARK_BLUE		0x000080
# define BLUE			0x0000FF
# define LIGHT_BLUE		0x8080FF
# define RED_BLUE		0xFF00FF

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
}				t_env;
