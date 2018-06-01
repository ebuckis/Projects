/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_new_ldir.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 12:43:44 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 11:59:13 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_error_file(int error, char *s)
{
	char	*s1;
	char	*s2;
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	s1 = "ls: ";
	s2 = NULL;
	if (error == -3)
		s2 = ": Not a directory";
	else if (error == -2)
		s2 = ": No such file or directory";
	if (error == -1)
	{
		s2 = ": Permission denied";
		i = ft_strlen(s);
		while (s[i - 1] != '/' && i > 0)
			i--;
	}
	tmp = ft_strjoin(s1, s + i);
	str = ft_strjoin(tmp, s2);
	free(tmp);
	return (str);
}

void		ft_init_ldir(t_ldir *ld)
{
	ld->path = NULL;
	ld->file = NULL;
	ft_bzero(ld->droit, 11);
	ld->link = 0;
	ld->link_l = 0;
	ld->usr = NULL;
	ld->usr_l = 0;
	ld->group = NULL;
	ld->group_l = 0;
	ld->size = 0;
	ld->size_l = 0;
	ld->time = 0;
	ld->date = NULL;
	ft_bzero(ld->date_aff, 13);
	ld->date_type = 0;
	ld->error = 0;
	ld->under = NULL;
	ld->block = 0;
	ld->major = 0;
	ld->major_l = 0;
	ld->minor = 0;
	ld->minor_l = 0;
}

char		*ft_file_name(char *s)
{
	char	*str;
	int		i;

	i = ft_strlen(s);
	while (i >= 0 && s[i] != '/')
	{
		i--;
	}
	i++;
	str = ft_strdup(s + i);
	return (str);
}

t_ldir		*ft_new_ldir(int error, char *s, t_opt ret)
{
	t_ldir	*ld;

	ld = (t_ldir *)malloc(sizeof(t_ldir));
	ft_init_ldir(ld);
	if (error < 0)
	{
		ld->file = ft_error_file(error, s);
		ld->error = error;
		ld->next = NULL;
	}
	else
	{
		ld->path = ft_strdup(s);
		ld->file = ft_file_name(s);
		ft_search_info(ld, s, ret);
		if (ld->droit[0] == 'd')
		{
			ld->under = ft_recursive(s, ld->file, ret);
		}
	}
	return (ld);
}
