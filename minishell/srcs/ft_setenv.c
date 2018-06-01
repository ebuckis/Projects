/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_setenv.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 12:14:00 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/31 13:46:57 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_add_suite(t_env *new, int i, char *s)
{
	if (i == 1)
	{
		free(new->next->env);
		new->next->env = s;
	}
	if (i == 2)
	{
		new = ft_malloc_env(s);
		free(s);
	}
	else
	{
		new->next = ft_malloc_env(s);
		free(s);
	}
}

t_env			*ft_add_env(t_env *l, char *name, char *val)
{
	t_env		*new;
	char		*s;
	int			n;

	if (!name)
		return (l);
	n = ft_strlen(name);
	if (!(s = ft_strjoin(name, "=")))
		return (l);
	if (val)
		if (!(s = ft_strjoin_del(s, val)))
			return (l);
	if (!l)
	{
		l = ft_malloc_env(s);
		free(s);
		return (l);
	}
	new = l;
	while (new->next && !(ft_strncmp(name, new->next->env, n) == 0
		&& new->next->env[n] == '='))
		new = new->next;
	new->next ? (ft_add_suite(new, 1, s)) : (ft_add_suite(new, 0, s));
	return (l);
}

void			ft_setenv(t_mini *m, t_env *l)
{
	if (!m->arg[1])
		ft_print_env(l);
	else if (ft_strchr(m->arg[1], '='))
		ft_putendl("Error, le signe '=' est strictement interdit");
	else if (!m->arg[2])
		l = ft_add_env(l, m->arg[1], NULL);
	else if (ft_strchr(m->arg[2], '='))
		ft_putendl("Error, le signe '=' est strictement interdit");
	else if (!m->arg[3])
		l = ft_add_env(l, m->arg[1], m->arg[2]);
	else
		ft_putendl("Trop d'arguments");
}
