/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_oth.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 16:16:18 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 16:27:46 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_space(int max, int lg)
{
	int		i;

	i = 0;
	while (lg + i <= max)
	{
		ft_putchar(' ');
		i++;
	}
}

void		ft_print_oth(t_arg *lst, t_ldir *tmp, int i)
{
	if (i == 1)
	{
		ft_putstr(" -> ");
		ft_putstr(tmp->l_symb);
	}
	if (i == 2)
	{
		ft_putstr_fd(tmp->file, 2);
		ft_putchar_fd('\n', 2);
	}
	if (i > 2)
	{
		ft_putstr("total ");
		if (i == 3)
			ft_putnbr(tmp->under->block);
		if (i == 4)
			ft_putnbr(lst->ld->block);
		ft_putstr(":\n");
	}
}

void		ft_print_info(t_ldir *ld)
{
	ft_putstr(ld->droit);
	ft_print_space(ld->link_l + 1, ft_int_len(ld->link));
	ft_putnbr(ld->link);
	ft_print_space(ld->usr_l + 1, ft_strlen(ld->usr));
	ft_putstr(ld->usr);
	ft_print_space(ld->group_l + 1, ft_strlen(ld->group));
	ft_putstr(ld->group);
	if (ld->size != -1)
	{
		ft_print_space(ld->size_l, ft_int_len(ld->size));
		ft_putnbr(ld->size);
	}
	else
	{
		ft_print_space(ld->major_l, ft_int_len(ld->major));
		ft_putnbr(ld->major);
		ft_putchar(',');
		ft_print_space(ld->minor_l, ft_int_len(ld->minor));
		ft_putnbr(ld->minor);
	}
	ft_print_space(2, 1);
	ft_putstr(ld->date_aff);
	ft_putchar(' ');
}

void		ft_print_under(t_ldir *ld, t_opt ret)
{
	t_ldir	*tmp;

	tmp = ld;
	while (tmp)
	{
		if (tmp->droit[0] == 'd' && ft_condition_dir(ret, tmp->file))
		{
			ft_putchar('\n');
			ft_putstr(tmp->path);
			ft_putendl(":");
			if (tmp->under && tmp->under->error != -4)
			{
				if (tmp->under->error != -1 && ret.l == 1)
					ft_print_oth(NULL, tmp, 3);
				ft_print_ld(tmp->under, ret);
			}
		}
		tmp = tmp->next;
	}
}
