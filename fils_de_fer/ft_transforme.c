/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_transform.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 13:08:30 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 17:27:10 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int		sort_y(t_chaine *lst)
{
	int y;

	y = 0;
	while (lst)
	{
		y++;
		lst = lst->next;
	}
	return (y);
}

static int		verif_int(t_chaine *s)
{
	int x;

	x = s->x;
	while (s)
	{
		if (x != s->x)
			return (0);
		s = s->next;
	}
	return (1);
}

static int		**ft_allocation(int **tab, t_chaine *s)
{
	int x;

	x = 0;
	tab = (int **)malloc(sizeof(int *) * (sort_y(s)));
	if (tab)
	{
		while (x < sort_y(s))
		{
			tab[x] = (int *)malloc(sizeof(int) * s->x);
			if (tab[x])
				x++;
			else
			{
				ft_free_tab(tab, x);
				ft_putstr("alloc. error\n");
				return (NULL);
			}
		}
		return (tab);
	}
	ft_putstr("alloc. error\n");
	return (NULL);
}

static int		**list_atoi(t_chaine *lst, int **tab, t_coord *v)
{
	v->y = 0;
	v->z = ft_atoi(lst->l_split[0]);
	v->zb = v->z;
	if (verif_int(lst) != 0)
	{
		while (lst != NULL)
		{
			v->x = 0;
			while (v->x < lst->x)
			{
				tab[v->y][v->x] = ft_atoi(lst->l_split[v->x]);
				v->z = (tab[v->y][v->x] > v->z) ? tab[v->y][v->x] : v->z;
				v->zb = (tab[v->y][v->x] < v->zb) ? tab[v->y][v->x] : v->zb;
				v->x++;
			}
			v->y++;
			lst = lst->next;
		}
		return (tab);
	}
	ft_putstr("invalid file\n");
	return (NULL);
}

int				ft_transforme(t_chaine *lst)
{
	int			**tab;
	t_coord		vmax;

	tab = NULL;
	if ((tab = ft_allocation(tab, lst)))
	{
		if ((tab = list_atoi(lst, tab, &vmax)))
		{
			ft_free_list(lst);
			tracage(tab, vmax);
			return (1);
		}
		ft_free_tab(tab, vmax.y);
	}
	ft_free_list(lst);
	return (0);
}
