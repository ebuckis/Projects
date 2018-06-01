/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 11:22:48 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 08:43:08 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define PTH 100
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_fract
{
	void			*p[3];
	int				type;
	int				pause;
	int				x;
	int				y;
	int				i;
	int				it_max;
	long double		x1;
	long double		x2;
	long double		y1;
	long double		y2;
	int				i_x;
	int				i_y;
	long double		cr;
	long double		ci;
	long double		zr;
	long double		zi;
	long double		zoom_x;
	long double		zoom_y;
	long double		tmp;
	int				c;
	int				y_tmp;
}					t_fract;
void				ft_mandelbrot(t_fract *s);
void				ft_julia(t_fract *s);
void				ft_newton(t_fract *s);
void				lancement_fract(t_fract *s);
int					ft_loop_hook(t_fract *s);
int					ft_expose_hook(t_fract *s);
int					ft_key_event(int keycode, t_fract *s);
int					ft_mouse_hook(int button, int x, int y, t_fract *s);
int					ft_event_hook(int x, int y, t_fract *s);
void				ft_init_zero(t_fract *s);
void				bandeau_cmd(t_fract *s);
void				bandeau_fract(t_fract *s);
void				ft_fill_img(int x, int y, void *img, int clr);
void				ft_init_julia(t_fract *s);
void				ft_init_mand(t_fract *s);
void				ft_init_newton(t_fract *s);
int					ft_fill_clr(t_fract s);
t_fract				ft_divise(t_fract *tab, int i, t_fract s);

#endif
