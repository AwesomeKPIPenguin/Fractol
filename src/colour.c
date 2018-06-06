//
// Created by Dimon on 06.06.2018.
//

#include "../fractol.h"

int		ft_getcolour(int i, int i_max)
{
	return ((int)(i * (double)BLACK / (double)i_max));
}
