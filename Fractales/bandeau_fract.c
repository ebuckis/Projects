/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bandeau_fract.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 09:23:06 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/26 14:11:32 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void		traits_tab(t_fract *s)
{
	s->p[2] = mlx_new_image(s->p[0], 400, 1200);
	s->y = 0;
	while (s->y < 1200)
	{
		s->x = 0;
		while (s->x < 400)
		{
			if (s->y < 2 || s->y > 1196 || s->x < 2 || s->x > 397 ||
					(s->y > 397 && s->y < 402) || (s->y > 797 && s->y < 802))
				ft_fill_img(s->x, s->y, s->p[2], 0xFFFFFF);
			s->x++;
		}
		s->y++;
	}
	mlx_put_image_to_window(s->p[0], s->p[1], s->p[2], 1000, 0);
	mlx_destroy_image(s->p[0], s->p[2]);
}

void		bandeau_fract(t_fract *s)
{
	s->c = 1;
	traits_tab(s);
	s->i_x = 396;
	s->i_y = 396;
	s->p[2] = mlx_new_image(s->p[0], 396, 396);
	ft_init_mand(s);
	ft_mandelbrot(s);
	mlx_put_image_to_window(s->p[0], s->p[1], s->p[2], 1002, 2);
	ft_init_julia(s);
	ft_julia(s);
	mlx_put_image_to_window(s->p[0], s->p[1], s->p[2], 1002, 402);
	ft_init_newton(s);
	ft_newton(s);
	mlx_put_image_to_window(s->p[0], s->p[1], s->p[2], 1002, 802);
	mlx_destroy_image(s->p[0], s->p[2]);
}
