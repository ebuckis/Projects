/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recursive.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 17:22:27 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 14:08:12 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_condition_dir(t_opt ret, char *file)
{
	if (ret.rmaj == 0)
		return (0);
	if (ft_strcmp(file, ".") == 0)
		return (0);
	if (ft_strcmp(file, "..") == 0)
		return (0);
	return (1);
}

t_ldir		*ft_recursive(char *s, char *file, t_opt ret)
{
	t_ldir	*ld;
	DIR		*dir;

	ld = NULL;
	if (ft_condition_dir(ret, file) == 1)
	{
		dir = opendir(s);
		if (!dir)
		{
			ld = ft_new_ldir(-1, s, ret);
			return (ld);
		}
		ld = ft_read_dir(s, ret, dir, ld);
		closedir(dir);
	}
	return (ld);
}
