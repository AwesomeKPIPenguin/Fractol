//
// Created by Dimon on 06.06.2018.
//

#include "../fractol.h"

int		ft_getcolour(double i, int i_max)
{
	int		colour = (int)((double)i * (double)GREEN / (double)i_max);

	return (colour);
}
