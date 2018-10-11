/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 17:03:48 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 17:32:11 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_coord
{
	int		x;
	int		y;
	int		z;
	int		zb;
}				t_coord;
typedef struct	s_chaine
{
	int				x;
	int				y;
	char			**l_split;
	struct s_chaine	*next;
}				t_chaine;
t_chaine		*ft_lecture(int fd);
int				ft_transforme(t_chaine *lst);
void			tracage(int **tab, t_coord vmax);
int				ft_ahextoi(char *s);
int				ft_key_action(int keycode, void **p);
void			ft_point(t_coord vmax, int **tab, void **p);
int				ft_color_z(t_coord *cd, t_coord pt);
void			ft_str_image(t_coord pt, void *img, int *t);
void			ft_free_list(t_chaine *lst);
void			ft_free_tab(int **tab, int x);

#endif
