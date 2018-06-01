/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_all.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 16:27:15 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 16:27:19 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_del_malloc(void *data)
{
	if (data)
	{
		free(data);
		data = NULL;
	}
}

void		ft_free_arg(t_arg *lst)
{
	ft_del_malloc((void *)(lst->arg));
	ft_del_malloc((void *)(lst));
}

void		ft_free_data(t_ldir *ld)
{
	ft_del_malloc((void *)(ld->file));
	ft_del_malloc((void *)(ld->path));
	ft_del_malloc((void *)(ld->usr));
	ft_del_malloc((void *)(ld->group));
	ft_del_malloc((void *)(ld));
}

void		ft_free_ldir(t_ldir *ld)
{
	if (!ld)
		return ;
	ft_free_ldir(ld->next);
	ft_free_ldir(ld->under);
	ft_free_data(ld);
}

void		ft_free_all(t_arg *lst)
{
	if (!lst)
		return ;
	ft_free_all(lst->next);
	ft_free_ldir(lst->ld);
	ft_free_arg(lst);
}
