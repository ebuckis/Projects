/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init_zero.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/18 16:22:47 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 16:30:07 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		ft_init_newton(t_fract *s)
{
	s->pause = 0;
	s->x1 = -2;
	s->x2 = 2;
	s->y1 = -2;
	s->y2 = 2;
	s->it_max = 10;
	s->zoom_x = s->i_x / (s->x2 - s->x1);
	s->zoom_y = s->i_y / (s->y2 - s->y1);
}

void		ft_init_julia(t_fract *s)
{
	s->pause = 0;
	s->cr = 0.286;
	s->ci = 0.01;
	s->x1 = -1;
	s->x2 = 1;
	s->y1 = -1.2;
	s->y2 = 1.2;
	s->it_max = 50;
	s->zoom_x = s->i_x / (s->x2 - s->x1);
	s->zoom_y = s->i_y / (s->y2 - s->y1);
}

void		ft_init_mand(t_fract *s)
{
	s->pause = 0;
	s->x1 = -2.1;
	s->x2 = 0.6;
	s->y1 = -1.2;
	s->y2 = 1.2;
	s->it_max = 30;
	s->zoom_x = s->i_x / (s->x2 - s->x1);
	s->zoom_y = s->i_y / (s->y2 - s->y1);
}

void		ft_init_zero(t_fract *s)
{
	s->i_x = 1000;
	s->i_y = 1000;
	if (s->type == 1)
		ft_init_mand(s);
	if (s->type == 2)
		ft_init_julia(s);
	if (s->type == 3)
		ft_init_newton(s);
	lancement_fract(s);
}
