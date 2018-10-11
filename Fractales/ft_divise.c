/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_divise.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 14:57:28 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 16:26:30 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_fract		ft_divise(t_fract *tab, int i, t_fract s)
{
	tab[i].p[0] = s.p[0];
	tab[i].p[1] = s.p[1];
	tab[i].p[2] = s.p[2];
	tab[i].x = s.x;
	tab[i].y = s.i_y * i / PTH;
	tab[i].it_max = s.it_max;
	tab[i].x1 = s.x1;
	tab[i].x2 = s.x2;
	tab[i].y1 = s.y1;
	tab[i].y2 = s.y2;
	tab[i].i_x = s.i_x;
	tab[i].i_y = s.i_y;
	tab[i].ci = s.ci;
	tab[i].cr = s.cr;
	tab[i].c = s.c;
	tab[i].zoom_y = s.zoom_y;
	tab[i].zoom_x = s.zoom_x;
	tab[i].y_tmp = s.i_y * (i + 1) / PTH;
	return (tab[i]);
}
