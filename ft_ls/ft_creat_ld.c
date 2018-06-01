/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_creat_ld.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 16:31:30 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 16:32:02 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_ldir		*ft_init_first(t_ldir *ld, char *str, t_opt ret)
{
	ld = ft_new_ldir(0, str, ret);
	ld->next = NULL;
	return (ld);
}

t_ldir		*ft_add_ldir(t_ldir *ld, char *str, t_opt ret)
{
	t_ldir			*new;

	new = ft_new_ldir(0, str, ret);
	new->next = ld->next;
	ld->next = new;
	return (ld);
}
