/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_newton.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 11:14:12 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 16:57:04 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_boucle(t_fract s)
{
	long double	val;
	int			clr;

	s.i = 0;
	while (s.i < s.it_max)
	{
		s.zr = s.cr * s.cr;
		s.zi = s.ci * s.ci;
		val = 3.0 * ((s.zr - s.zi) * (s.zr - s.zi) + 4.0 * s.zr * s.zi);
		s.tmp = s.cr;
		s.cr = (2.0 / 3.0) * s.cr + (s.zr - s.zi) / val;
		s.ci = (2.0 / 3.0) * s.ci - 2.0 * s.tmp * s.ci / val;
		s.i++;
	}
	if (s.cr > 0.0)
		clr = ft_fill_clr(s);
	else if ((s.cr < -0.3) && (s.ci > 0.0))
		clr = ft_fill_clr(s) / 256;
	else
		clr = ft_fill_clr(s) / 256 / 256;
	ft_fill_img(s.x, s.y, s.p[2], clr);
}

static void	*ft_boucle(void *arg)
{
	t_fract s;

	s = *(t_fract *)arg;
	while (s.y < s.i_y && s.y < s.y_tmp)
	{
		s.x = 0;
		while (s.x < s.i_x)
		{
			s.cr = s.x / s.zoom_x + s.x1;
			s.ci = s.y / s.zoom_y + s.y1;
			ft_init_boucle(s);
			s.x++;
		}
		s.y++;
	}
	pthread_exit(NULL);
}

void		ft_newton(t_fract *s)
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
