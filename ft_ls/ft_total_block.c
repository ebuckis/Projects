/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_total_block.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 15:37:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 15:13:02 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_sort_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void		ft_init_tmp(t_tmp *a)
{
	a->link = 0;
	a->usr = 0;
	a->grp = 0;
	a->size = 0;
	a->major = 0;
	a->minor = 0;
}

void		ft_assignation(t_ldir *ld, t_tmp a, int block)
{
	t_ldir	*tmp;

	tmp = ld;
	if (a.size < a.minor + a.major + 2)
		a.size = (a.minor + a.major + 2);
	while (tmp)
	{
		if (tmp->file != NULL)
		{
			tmp->block = block;
			tmp->link_l = a.link;
			tmp->usr_l = a.usr;
			tmp->group_l = a.grp;
			tmp->size_l = a.size;
			tmp->major_l = a.major;
			tmp->minor_l = a.minor;
		}
		tmp = tmp->next;
	}
}

void		ft_total_block(t_ldir *ld)
{
	t_ldir	*tmp;
	int		block;
	t_tmp	a;

	block = 0;
	tmp = ld;
	ft_init_tmp(&a);
	while (tmp)
	{
		if (tmp->file != NULL)
		{
			block += tmp->block;
			a.link = ft_sort_max(a.link, tmp->link_l);
			a.usr = ft_sort_max(a.usr, tmp->usr_l);
			a.grp = ft_sort_max(a.grp, tmp->group_l);
			a.size = ft_sort_max(a.size, tmp->size_l);
			a.major = ft_sort_max(a.major, tmp->major_l);
			a.minor = ft_sort_max(a.minor, tmp->minor_l);
		}
		if (tmp->under)
			ft_total_block(tmp->under);
		tmp = tmp->next;
	}
	ft_assignation(ld, a, block);
}
