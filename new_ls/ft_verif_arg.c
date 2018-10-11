/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_verif_arg.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/13 14:49:53 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 10:03:35 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_verif_arg(int ac, char **av, int i, t_opt ret)
{
	t_arg	*lst;

	lst = NULL;
	if (i == ac)
	{
		if ((lst = ft_save_classic_arg()))
			return (ft_lancement(lst, ret));
	}
	else
	{
		if (!(lst = ft_save_arg(i, ac, av)))
			return (0);
		return (ft_lancement(lst, ret));
	}
	return (0);
}
