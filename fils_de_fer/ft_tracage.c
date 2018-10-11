/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tracage.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 11:28:04 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 16:53:18 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		tracage(int **tab, t_coord vmax)
{
	void	*p[3];

	p[0] = mlx_init();
	p[1] = mlx_new_window(p[0], 1400, 1200, "test");
	p[2] = mlx_new_image(p[0], 2000, 2000);
	ft_point(vmax, tab, p);
	ft_free_tab(tab, vmax.y);
	mlx_put_image_to_window(p[0], p[1], p[2], 0, 0);
	mlx_key_hook(p[1], ft_key_action, p);
	mlx_loop(p[0]);
}
