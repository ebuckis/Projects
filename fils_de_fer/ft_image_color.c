/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_image_color.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/28 14:13:58 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 16:50:36 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		ft_str_image(t_coord pt, void *img, int *t)
{
	char	*str;

	str = mlx_get_data_addr(img, &t[0], &t[1], &t[2]);
	str[(t[1] * pt.y) + pt.x * 4 + 2] = t[3] / (256 * 256);
	str[(t[1] * pt.y) + pt.x * 4 + 1] = (t[3] / 256) % 256;
	str[(t[1] * pt.y) + pt.x * 4] = t[3] % 256;
}

static int	color_rgb(int c0, int c1, float a)
{
	int		color;
	t_coord	rgb[3];

	if (c0 == c1)
		return (c0);
	a = fabsf(a / 100);
	rgb[0].x = c0 / (256 * 256);
	rgb[0].y = (c0 / 256) % 256;
	rgb[0].z = c0 % 256;
	rgb[1].x = c1 / (256 * 256);
	rgb[1].y = (c1 / 256) % 256;
	rgb[1].z = c1 % 256;
	rgb[2].x = rgb[0].x + (rgb[1].x - rgb[0].x) * a;
	rgb[2].y = rgb[0].y + (rgb[1].y - rgb[0].y) * a;
	rgb[2].z = rgb[0].z + (rgb[1].z - rgb[0].z) * a;
	color = (rgb[2].x * 256 * 256) + (rgb[2].y * 256) + rgb[2].y;
	return (color);
}

int			ft_color_z(t_coord *cd, t_coord pt)
{
	int		clr;
	float	a;

	if (cd[0].zb == cd[1].zb)
		return (cd[0].zb);
	if (abs(cd[0].x - cd[1].x) < abs(cd[0].y - cd[1].y))
		a = (pt.y - cd[0].y) * 100 / (cd[1].y - cd[0].y);
	else
		a = (pt.x - cd[0].x) * 100 / abs(cd[1].x - cd[0].x);
	clr = color_rgb(cd[0].zb, cd[1].zb, a);
	return (clr);
}
