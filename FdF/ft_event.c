/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_event.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 10:30:53 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/28 15:07:00 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_black_win(void **p)
{
	void	*img;

	img = mlx_new_image(p[0], 2000, 2000);
	mlx_put_image_to_window(p[0], p[1], img, 0, 0);
}

int		ft_key_action(int keycode, void **p)
{
	static int	x = 0;
	static int	y = 0;
	int			pas;

	pas = 25;
	ft_putnbr(keycode);
	if (keycode == 125)
		y += pas;
	if (keycode == 124)
		x += pas;
	if (keycode == 126)
		y -= pas;
	if (keycode == 123)
		x -= pas;
	if (keycode == 53)
		exit(1);
	ft_black_win(p);
	mlx_put_image_to_window(p[0], p[1], p[2], x, y);
	return (0);
}
