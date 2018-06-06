//
// Created by Dimon on 06.06.2018.
//

#include "../fractol.h"

t_parg	ft_pargnew(t_env *env, int section)
{
	t_parg	parg;

	parg.env = env;
	parg.section = section;
	return (parg);
}