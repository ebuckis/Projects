/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_gestion_coord.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/28 14:14:08 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 16:54:37 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_calcul_y(t_coord *cd, void **p, int *t, t_coord pt)
{
	while (pt.y != cd[1].y)
	{
		pt.x = cd[0].x + (((cd[1].x - cd[0].x) *
					(pt.y - cd[0].y)) / (cd[1].y - cd[0].y));
		t[3] = ft_color_z(cd, pt);
		ft_str_image(pt, p[2], t);
		pt.y = (pt.y < cd[1].y) ? (pt.y + 1) : (pt.y - 1);
	}
}

static void		ft_calcul_x(t_coord *cd, void **p, int *t, t_coord pt)
{
	while (pt.x != cd[1].x)
	{
		pt.y = cd[0].y + (((cd[1].y - cd[0].y) *
					(pt.x - cd[0].x)) / (cd[1].x - cd[0].x));
		t[3] = ft_color_z(cd, pt);
		ft_str_image(pt, p[2], t);
		pt.x = (pt.x < cd[1].x) ? (pt.x + 1) : (pt.x - 1);
	}
}

static void		segment(t_coord *cd, void **p)
{
	int		t[4];
	t_coord	pt;

	pt = cd[0];
	if (abs(cd[0].x - cd[1].x) < abs(cd[0].y - cd[1].y))
		ft_calcul_y(cd, p, t, pt);
	if (abs(cd[0].x - cd[1].x) >= abs(cd[0].y - cd[1].y))
		ft_calcul_x(cd, p, t, pt);
}

static t_coord	ft_coord(int **tab, int x, int y, t_coord vmax)
{
	t_coord s;

	s.z = tab[y][x];
	s.zb = (s.z < (vmax.z * 7 / 10)) ? (0x3a9d23) : (0xffffff);
	s.zb = (s.z == 0) ? (0x0131b4) : (s.zb);
	x *= 700 / vmax.x;
	y *= 700 / vmax.y;
	s.x = 700 + x - y;
	if (vmax.x + vmax.y < 100)
		s.y = 10 * (vmax.z - s.z) + (x / 2) + (y / 2);
	else
		s.y = (3 + 100 / (vmax.x + vmax.y)) *
			(vmax.z - s.z) + (x / 2) + (y / 2);
	return (s);
}

void			ft_point(t_coord vmax, int **tab, void **p)
{
	t_coord	cd[2];
	int		x;
	int		y;

	y = -1;
	while (y++ < vmax.y - 2)
	{
		x = -1;
		while (x++ < vmax.x - 2)
		{
			cd[0] = ft_coord(tab, x, y, vmax);
			cd[1] = ft_coord(tab, x + 1, y, vmax);
			segment(cd, p);
			cd[1] = ft_coord(tab, x, y + 1, vmax);
			segment(cd, p);
		}
	}
}
