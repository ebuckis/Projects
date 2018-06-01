/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fill_img.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 09:43:31 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 15:32:39 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		ft_fill_clr(t_fract s)
{
	int		r;
	int		g;
	int		b;
	int		clr;
	double	t;

	t = s.i;
	t += s.c % 100;
	t /= s.it_max;
	r = 255 * (0.5f + 0.5f * cos(2 * M_PI * (t + 0.0f)));
	g = 255 * (0.5f + 0.5f * cos(2 * M_PI * (t + 0.33f)));
	b = 255 * (0.5f + 0.5f * cos(2 * M_PI * (t + 0.67f)));
	clr = ((r * 256) + g) * 256 + b;
	return (clr);
}

void	ft_fill_img(int x, int y, void *img, int clr)
{
	char	*str;
	int		t[4];

	str = mlx_get_data_addr(img, &t[0], &t[1], &t[2]);
	str[(t[1] * y) + x * 4 + 2] = clr / (256 * 256);
	str[(t[1] * y) + x * 4 + 1] = (clr / 256) % 256;
	str[(t[1] * y) + x * 4] = clr % 256;
}
/*
** merci a aberneli
** pour sa formule cos sin
** que j'ai modifie a ma sauce =)
*/
