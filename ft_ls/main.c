/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 10:48:21 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/26 11:26:27 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	init_opt(t_opt *ret)
{
	ret->rmaj = 0;
	ret->r = 0;
	ret->a = 0;
	ret->l = 0;
	ret->t = 0;
}

int			main(int ac, char **av)
{
	t_opt	ret;
	int		i;

	init_opt(&ret);
	if (ac == 1)
	{
		if (ft_verif_arg(ac, av, 1, ret) != 0)
			return (0);
	}
	else
	{
		if ((i = ft_verif_flag(ac, av, &ret)) != 0)
		{
			if (ft_verif_arg(ac, av, i, ret) != 0)
				return (0);
		}
	}
	return (0);
}
