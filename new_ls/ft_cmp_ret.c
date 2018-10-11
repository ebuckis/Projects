/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cmp_ret.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 11:09:29 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 14:25:21 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_cmp_ret(t_arg *l1, t_arg *l2, t_opt ret)
{
	if (ret.t == 1)
	{
		if (l1->ld->time == l2->ld->time)
		{
			ret.t = 0;
			return (ft_cmp_ret(l1, l2, ret));
		}
		if (ret.r == 1 && l1->ld->time > l2->ld->time)
			return (1);
		else if (ret.r == 0 && l1->ld->time < l2->ld->time)
			return (1);
		return (0);
	}
	else
	{
		if (ret.r == 1 && ft_strcmp(l1->arg, l2->arg) < 0)
			return (1);
		else if (ret.r == 0 && ft_strcmp(l1->arg, l2->arg) > 0)
			return (1);
		return (0);
	}
}

int		ft_cmp_ldir(t_ldir *l1, t_ldir *l2, t_opt ret)
{
	if (ret.t == 1)
	{
		if (l1->time == l2->time)
		{
			ret.t = 0;
			return (ft_cmp_ldir(l1, l2, ret));
		}
		if (ret.r == 1 && l1->time > l2->time)
			return (1);
		else if (ret.r == 0 && l1->time < l2->time)
			return (1);
		return (0);
	}
	else
	{
		if (ret.r == 1 && ft_strcmp(l1->file, l2->file) < 0)
			return (1);
		else if (ret.r == 0 && ft_strcmp(l1->file, l2->file) > 0)
			return (1);
		return (0);
	}
}
