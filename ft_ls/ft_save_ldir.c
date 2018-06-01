/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_save_ldir.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 10:28:38 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 16:31:54 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_path_file(char *path, char *file)
{
	char	*str;
	char	*tmp;
	int		i;

	i = ft_strlen(path) - 1;
	if (path[i] != '/')
		tmp = ft_strjoin(path, "/");
	else
		tmp = ft_strdup(path);
	str = ft_strjoin(tmp, file);
	free(tmp);
	return (str);
}

t_ldir		*ft_empty_file(t_ldir *ld)
{
	ld = (t_ldir *)malloc(sizeof(t_ldir));
	ft_init_ldir(ld);
	ld->error = -4;
	ld->file = strdup("none");
	ld->next = NULL;
	return (ld);
}

t_ldir		*ft_read_dir(char *arg, t_opt ret, DIR *dir, t_ldir *ld)
{
	struct dirent	*entry;
	char			*str;

	while ((entry = readdir(dir)) != NULL)
	{
		if (ret.a == 1 || entry->d_name[0] != '.')
		{
			str = ft_path_file(arg, entry->d_name);
			if (!ld)
				ld = ft_init_first(ld, str, ret);
			else
				ld = ft_add_ldir(ld, str, ret);
			free(str);
		}
	}
	if (!ld)
	{
		ld = ft_empty_file(ld);
	}
	return (ld);
}

t_ldir		*ft_save_ldir(t_arg *lst, t_opt ret)
{
	t_ldir	*ld;
	DIR		*dir;

	ld = NULL;
	if (lst->error < 2)
	{
		ld = ft_new_ldir(lst->error, lst->arg, ret);
		ld->next = NULL;
	}
	else
	{
		dir = opendir(lst->arg);
		if (!dir)
		{
			ld = ft_new_ldir(-1, lst->arg, ret);
			ld->next = NULL;
			return (ld);
		}
		ld = ft_read_dir(lst->arg, ret, dir, ld);
		closedir(dir);
	}
	return (ld);
}
