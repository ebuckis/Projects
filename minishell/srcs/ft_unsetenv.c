/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_unsetenv.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 12:14:04 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/31 13:50:05 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_repalce_env(t_mini *m, t_env *new, t_env *l)
{
	t_env	*tmp;

	if (new == l)
	{
		l = l->next;
		free(new);
		new = NULL;
	}
	else
	{
		tmp = l;
		while (tmp && tmp->next != new)
			tmp = tmp->next;
		if (new->next != NULL)
		{
			free(tmp->next);
			tmp->next = new->next;
		}
		else
		{
			free(tmp->next);
			tmp->next = NULL;
		}
	}
}

static void	ft_del_env(t_mini *m, char *s, t_env *l)
{
	t_env	*new;
	int		i;
	int		j;

	i = 0;
	new = l;
	while (new)
	{
		j = 0;
		while (new->env[j] != '\0' && new->env[j] != '=' && new->env[j] == s[j])
			j++;
		if (new->env[j] == '\0' || new->env[j] == '=')
			ft_repalce_env(m, new, l);
		new = new->next;
		i++;
	}
}

void		ft_unsetenv(t_mini *m, t_env *l)
{
	int i;

	i = 1;
	if (!m->arg[1])
		ft_putendl("unset: not enough arguments");
	else
	{
		while (m->arg[i])
		{
			ft_del_env(m, m->arg[i], l);
			i++;
		}
	}
}
