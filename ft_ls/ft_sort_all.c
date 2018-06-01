/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_all.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 16:28:20 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 16:28:23 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_cmp_arg(t_arg *l1, t_arg *l2, t_opt ret)
{
	if (l1->error < -1 && l2->error < -1)
	{
		if (ft_strcmp(l1->arg, l2->arg) > 0)
			return (1);
	}
	else if (l1->error > l2->error)
		return (1);
	else if ((l1->error == 1 || l1->error == 2) && l2->error == l1->error)
		return (ft_cmp_ret(l1, l2, ret));
	return (0);
}

t_arg		*ft_sort_arg(t_arg *lst, t_opt ret)
{
	if (!lst)
		return (NULL);
	if (lst->next && ft_cmp_arg(lst, lst->next, ret) > 0)
		lst = ft_swap_arg(lst, lst->next);
	lst->next = ft_sort_arg(lst->next, ret);
	if (lst->next && ft_cmp_arg(lst, lst->next, ret) > 0)
	{
		lst = ft_swap_arg(lst, lst->next);
		lst->next = ft_sort_arg(lst->next, ret);
	}
	return (lst);
}

t_arg		*ft_sort_all(t_arg *lst, t_opt ret)
{
	t_arg	*tmp;

	tmp = lst;
	lst = ft_sort_arg(lst, ret);
	while (tmp)
	{
		tmp->ld = ft_sort_ldir(tmp->ld, ret);
		if (ret.l == 1)
			ft_total_block(tmp->ld);
		tmp = tmp->next;
	}
	return (lst);
}
