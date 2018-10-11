/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_all.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/17 09:48:09 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 16:25:01 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_ld(t_ldir *ld, t_opt ret)
{
	t_ldir	*tmp;

	tmp = ld;
	while (tmp)
	{
		if (tmp->error >= 0)
		{
			if (ret.l == 1)
				ft_print_info(tmp);
			ft_putstr(tmp->file);
			if (tmp->droit[0] == 'l' && ret.l == 1)
				ft_print_oth(NULL, tmp, 1);
			ft_putchar('\n');
		}
		else
			ft_print_oth(NULL, tmp, 2);
		tmp = tmp->next;
	}
	if (ret.rmaj == 1)
		ft_print_under(ld, ret);
}

void		ft_print_all(t_arg *lst, t_opt ret)
{
	t_arg	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->error == 2)
		{
			if (lst->next)
			{
				ft_putstr(tmp->arg);
				ft_putendl(":");
			}
			if (tmp->ld && ret.l == 1)
				ft_print_oth(tmp, NULL, 4);
		}
		ft_print_ld(tmp->ld, ret);
		if (tmp->next && (tmp->error > 0 && tmp->next->error == 2))
			ft_putchar('\n');
		tmp = tmp->next;
	}
}
