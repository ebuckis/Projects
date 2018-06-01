/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sort_ldir.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 16:28:51 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 16:28:55 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_ldir		*ft_sort_ldir2(t_ldir *ld, t_opt ret)
{
	if (!ld || !ld->file)
		return (NULL);
	if (ld->under)
	{
		ld->under = ft_sort_ldir(ld->under, ret);
	}
	if (ld->next && ft_cmp_ldir(ld, ld->next, ret) > 0)
		ld = ft_swap_ldir(ld, ld->next);
	ld->next = ft_sort_ldir(ld->next, ret);
	if (ld->next && ft_cmp_ldir(ld, ld->next, ret) > 0)
	{
		ld = ft_swap_ldir(ld, ld->next);
		ld->next = ft_sort_ldir(ld->next, ret);
	}
	return (ld);
}

t_ldir		*ft_sort_ldir(t_ldir *ld, t_opt ret)
{
	if (ld == NULL)
		return (NULL);
	ld = ft_sort_ldir2(ld, ret);
	return (ld);
}
