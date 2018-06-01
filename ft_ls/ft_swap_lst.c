/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_swap_lst.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 11:19:28 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 11:25:09 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_arg		*ft_swap_arg(t_arg *l1, t_arg *l2)
{
	l1->next = l2->next;
	l2->next = l1;
	return (l2);
}

t_ldir		*ft_swap_ldir(t_ldir *l1, t_ldir *l2)
{
	l1->next = l2->next;
	l2->next = l1;
	return (l2);
}
