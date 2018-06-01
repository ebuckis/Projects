/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 11:18:44 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 16:25:28 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	lancement_fract(t_fract *s)
{
	s->p[2] = mlx_new_image(s->p[0], 1000, 1000);
	s->zoom_x = s->i_x / (s->x2 - s->x1);
	s->zoom_y = s->i_y / (s->y2 - s->y1);
	if (s->type == 1)
		ft_mandelbrot(s);
	if (s->type == 2)
		ft_julia(s);
	if (s->type == 3)
		ft_newton(s);
	mlx_put_image_to_window(s->p[0], s->p[1], s->p[2], 0, 0);
}

int		creat_win(t_fract *s)
{
	s->p[0] = mlx_init();
	s->p[1] = mlx_new_window(s->p[0], 1400, 1200, "Fractal");
	bandeau_fract(s);
	bandeau_cmd(s);
	ft_init_zero(s);
	mlx_hook(s->p[1], 6, (1L << 17), ft_event_hook, s);
	mlx_mouse_hook(s->p[1], ft_mouse_hook, s);
	mlx_key_hook(s->p[1], ft_key_event, s);
	mlx_loop_hook(s->p[0], ft_loop_hook, s);
	mlx_loop(s->p[0]);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fract s;

	if (argc == 2 && ft_strcmp(argv[1], "Mandelbrot") == 0)
		s.type = 1;
	else if (argc == 2 && ft_strcmp(argv[1], "Julia") == 0)
		s.type = 2;
	else if (argc == 2 && ft_strcmp(argv[1], "Newton") == 0)
		s.type = 3;
	else
	{
		ft_putstr("invalid argument\n ---> Mandelbrot\n");
		ft_putstr(" ---> Julia\n ---> Newton\n");
		return (0);
	}
	creat_win(&s);
	return (0);
}
