/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_setenv.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 12:14:00 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/05 09:51:18 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_add_suite(char *s, t_env *l, int n, char *name)
{
	t_env		*new;
	t_env		*tmp;

	new = l;
	while (new && !(ft_strncmp(name, new->env, n) == 0 && new->env[n] == '='))
	{
		tmp = new;
		new = new->next;
	}
	if (new != NULL)
	{
		free(new->env);
		new->env = s;
	}
	else
	{
		tmp->next = ft_malloc_env(s);
		free(s);
	}
}

t_env			*ft_add_env(t_env *l, char *name, char *val)
{
	char		*s;
	int			n;

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
	ft_add_suite(s, l, n, name);
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
