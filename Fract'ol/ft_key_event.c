/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_key_event.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 15:55:46 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 16:48:11 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom_plus(t_fract *s)
{
	long double d;

	d = fabsl(s->x2 - s->x1);
	if (d > 0.000000000000001)
	{
		s->tmp = s->x1 + 0.05 * (s->x2 - s->x1) / 2;
		s->x2 -= 0.05 * (s->x2 - s->x1) / 2;
		s->x1 = s->tmp;
		s->tmp = s->y1 + 0.05 * (s->y2 - s->y1) / 2;
		s->y2 -= 0.05 * (s->y2 - s->y1) / 2;
		s->y1 = s->tmp;
		lancement_fract(s);
	}
}

void	ft_zoom_moins(t_fract *s)
{
	s->tmp = s->x1 - 0.05 * (s->x2 - s->x1) / 2;
	s->x2 += 0.05 * (s->x2 - s->x1) / 2;
	s->x1 = s->tmp;
	s->tmp = s->y1 - 0.05 * (s->y2 - s->y1) / 2;
	s->y2 += 0.05 * (s->y2 - s->y1) / 2;
	s->y1 = s->tmp;
	lancement_fract(s);
}

void	ft_mvt(t_fract *s, int i)
{
	if (i == 123)
	{
		s->tmp = s->x1 - (s->x2 - s->x1) * 0.1;
		s->x2 -= (s->x2 - s->x1) * 0.1;
		s->x1 = s->tmp;
	}
	if (i == 124)
	{
		s->tmp = s->x1 + (s->x2 - s->x1) * 0.1;
		s->x2 += (s->x2 - s->x1) * 0.1;
		s->x1 = s->tmp;
	}
	if (i == 125)
	{
		s->tmp = s->y1 + (s->y2 - s->y1) * 0.1;
		s->y2 += (s->y2 - s->y1) * 0.1;
		s->y1 = s->tmp;
	}
	if (i == 126)
	{
		s->tmp = s->y1 - (s->y2 - s->y1) * 0.1;
		s->y2 -= (s->y2 - s->y1) * 0.1;
		s->y1 = s->tmp;
	}
}

void	ft_change_it(t_fract *s, int keycode)
{
	if (keycode == 75)
	{
		if (s->it_max > 19)
			s->it_max -= 10;
		else if (s->it_max > 10)
			s->it_max = 10;
		else if (s->it_max <= 10 && s->it_max > 1)
			s->it_max -= 1;
	}
	else if (keycode == 67)
	{
		if (s->it_max >= 10)
			s->it_max += 10;
		else if (s->it_max < 10 && s->it_max > 0)
			s->it_max += 1;
	}
}

int		ft_key_event(int keycode, t_fract *s)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 69)
		ft_zoom_plus(s);
	else if (keycode == 78 && (s->x2 - s->x1) < 6)
		ft_zoom_moins(s);
	else if (keycode >= 123 && keycode <= 126)
		ft_mvt(s, keycode);
	else if (keycode == 75 || keycode == 67)
		ft_change_it(s, keycode);
	else if (keycode == 35)
	{
		if (s->pause == 1)
			s->pause = 0;
		else
			s->pause = 1;
		return (0);
	}
	else if (keycode == 8)
		s->c += 3;
	else
		return (0);
	lancement_fract(s);
	return (0);
}
