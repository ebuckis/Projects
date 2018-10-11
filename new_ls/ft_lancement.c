/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lancement.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 12:37:16 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/27 15:22:40 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_lancement(t_arg *lst, t_opt ret)
{
	t_arg	*tmp;

	tmp = lst;
	while (tmp)
	{
		tmp->ld = ft_save_ldir(tmp, ret);
		tmp = tmp->next;
	}
	lst = ft_sort_all(lst, ret);
	ft_print_all(lst, ret);
	ft_free_all(lst);
	return (1);
}
