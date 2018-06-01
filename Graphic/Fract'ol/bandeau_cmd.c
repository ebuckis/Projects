/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bandeau_cmd.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 08:24:28 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/27 15:56:14 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr_to_win(t_fract *s)
{
	mlx_string_put(s->p[0], s->p[1], 20, 1020, 0xFFFFFF, "molette : zoom");
	mlx_string_put(s->p[0], s->p[1], 60, 1045, 0xFFFFFF, "+ - : zoom");
	mlx_string_put(s->p[0], s->p[1], 60, 1070, 0xFFFFFF, "* / : iterations");
	mlx_string_put(s->p[0], s->p[1], 60, 1095, 0xFFFFFF, "  p : pause");
	mlx_string_put(s->p[0], s->p[1], 60, 1120, 0xFFFFFF, "esc : fermer");
	mlx_string_put(s->p[0], s->p[1], 60, 1145, 0xFFFFFF, "  c : couleurs");
}

void	bandeau_cmd(t_fract *s)
{
	s->p[2] = mlx_new_image(s->p[0], 1000, 200);
	s->y = 0;
	while (s->y < 200)
	{
		s->x = 0;
		while (s->x < 1000)
		{
			if (s->y < 4 || s->y > 196 || s->x < 4 || s->x > 996)
				ft_fill_img(s->x, s->y, s->p[2], 0xFFFFFF);
			s->x++;
		}
		s->y++;
	}
	mlx_put_image_to_window(s->p[0], s->p[1], s->p[2], 0, 1000);
	ft_putstr_to_win(s);
	mlx_destroy_image(s->p[0], s->p[2]);
}
