/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_julia.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 11:48:56 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 16:56:45 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_init_boucle(t_fract s)
{
	int clr;

	s.zr = s.x / s.zoom_x + s.x1;
	s.zi = s.y / s.zoom_y + s.y1;
	s.i = 0;
	while (s.zr * s.zr + s.zi * s.zi < 4 && s.i < s.it_max)
	{
		s.tmp = s.zr;
		s.zr = s.zr * s.zr - s.zi * s.zi + s.cr;
		s.zi = 2 * s.zi * s.tmp + s.ci;
		s.i++;
	}
	clr = ft_fill_clr(s);
	if (s.i == s.it_max)
		ft_fill_img(s.x, s.y, s.p[2], 0);
	else
		ft_fill_img(s.x, s.y, s.p[2], clr);
}

static void		*ft_boucle(void *arg)
{
	t_fract s;

	s = *(t_fract *)arg;
	while (s.y < s.i_y && s.y < s.y_tmp)
	{
		s.x = 0;
		while (s.x < s.i_x)
		{
			ft_init_boucle(s);
			s.x++;
		}
		s.y++;
	}
	pthread_exit(NULL);
}

void			ft_julia(t_fract *s)
{
	int			i;
	pthread_t	t[PTH];
	t_fract		tab[PTH];

	i = 0;
	while (i < PTH)
	{
		tab[i] = ft_divise(tab, i, *s);
		i++;
	}
	i = 0;
	while (i < PTH)
	{
		pthread_create(&t[i], NULL, ft_boucle, (void *)&tab[i]);
		i++;
	}
	i = 0;
	while (i < PTH)
	{
		pthread_join(t[i], NULL);
		i++;
	}
}
