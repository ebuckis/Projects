/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lecture.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 08:54:38 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 17:31:50 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static t_chaine	*ft_newlist(char *line)
{
	t_chaine *s;

	s = (t_chaine *)malloc(sizeof(t_chaine));
	if (!s)
		return (NULL);
	s->l_split = ft_strsplit(line, ' ');
	s->x = cpt_mot(line, ' ');
	s->next = NULL;
	return (s);
}

t_chaine		*ft_lecture(int fd)
{
	char		*line;
	t_chaine	*lst;
	t_chaine	*new;

	lst = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (lst == NULL)
		{
			new = ft_newlist(line);
			lst = new;
		}
		else
		{
			new->next = ft_newlist(line);
			new = new->next;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (lst);
}
