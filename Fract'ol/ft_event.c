/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_event.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/13 17:11:36 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 15:19:39 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		ft_loop_hook(t_fract *s)
{
	char *str;
	void *p;

	str = ft_itoa(s->it_max);
	p = mlx_new_image(s->p[0], 100, 100);
	mlx_put_image_to_window(s->p[0], s->p[1], p, 250, 1070);
	mlx_string_put(s->p[0], s->p[1], 250, 1070, 0xFFFF00, str);
	if (s->type == 2 && s->pause == 1)
		mlx_string_put(s->p[0], s->p[1], 250, 1095, 0xFF00, "on");
	else
		mlx_string_put(s->p[0], s->p[1], 250, 1095, 0xFF0000, "off");
	mlx_destroy_image(s->p[0], p);
	return (0);
}

int		ft_event_hook(int x, int y, t_fract *s)
{
	if (s->pause == 1)
		if ((x >= 0 && x <= 1000) && (y >= 0 && y <= 1000) && s->type == 2)
		{
			s->cr = x * (s->x2 - s->x1);
			s->cr = s->cr / s->i_x + s->x1;
			s->ci = y * (s->y2 - s->y1);
			s->ci = s->ci / s->i_y + s->y1;
			mlx_destroy_image(s->p[0], s->p[2]);
			lancement_fract(s);
		}
	return (0);
}
/*
** ft_event_hook recupere en direct la pos de la souris
** uniquement quand type == 2 et qu'on est dans la fenetre
*/
