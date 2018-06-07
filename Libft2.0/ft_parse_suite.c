/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse_suite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/07 12:37:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 13:00:18 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_parse		*ft_init_parse(char *s)
{
	t_parse	*p;
	int		n;

	p = (t_parse *)malloc(sizeof(t_parse));
	if (!p)
		return (NULL);
	p->str = ft_memalloc(ft_strlen(s));
	if (!p->str)
		return (NULL);
	p->i = 0;
	p->j = 0;
	return (p);
}

int			ft_realloc(t_parse *p, char *s)
{
	char	*cpy;
	int		n;

	n = ft_strlen(s);
	cpy = ft_memalloc(n);
	cpy = ft_strcpy(cpy, p->str);
	free(p->str);
	p->str = cpy;
	return (0);
}

char		*ft_suite_line(t_parse *p, char *s, int i)
{
	char	*tmp;
	char	*cpy;

	tmp = NULL;
	if (i == 0)
		s[p->i] = '\0';
	if (i == 1)
	{
		s = ft_strjoin_del(s, "\\n");
	}
	get_next_line(0, &tmp);
	s = ft_strjoin_del(s, tmp);
	ft_realloc(p, s);
	free(tmp);
	return (s);
}

void		ft_end_while(t_parse *p, char *s)
{
	p->str[p->j] = s[p->i];
	p->i++;
	p->j++;
}
