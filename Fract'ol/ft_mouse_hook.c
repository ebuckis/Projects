/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mouse_hook.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 15:54:33 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 16:48:31 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom_souris(t_fract *s, int b, int x, int y)
{
	long double k;
	long double i;
	long double j;

	i = x;
	i = i / (1000 / (s->x2 - s->x1)) + s->x1;
	j = y;
	j = j / (1000 / (s->y2 - s->y1)) + s->y1;
	if (b == 5)
		k = 0.95;
	else if (b == 4 && (s->x2 - s->x1) < 6)
		k = 1.05;
	else
		return ;
	s->x1 = k * (s->x1 - i) + i;
	s->x2 = k * (s->x2 - i) + i;
	s->y1 = k * (s->y1 - j) + j;
	s->y2 = k * (s->y2 - j) + j;
	lancement_fract(s);
}

int		ft_mouse_hook(int button, int x, int y, t_fract *s)
{
	long double	d;

	if (button == 4)
		ft_zoom_souris(s, button, x, y);
	if (button == 5)
	{
		d = fabsl(s->x2 - s->x1);
		if (d > 0.0000000000000001)
			ft_zoom_souris(s, button, x, y);
	}
	if (button == 1 && x > 1000 && x < 1400)
	{
		if (y > 0 && y < 400)
			s->type = 1;
		if (y > 400 && y < 800)
			s->type = 2;
		if (y > 800 && y < 1200)
			s->type = 3;
		ft_init_zero(s);
	}
	return (0);
}
/*
** button 5 de-zoom
** buttom 4 zoom
*/
