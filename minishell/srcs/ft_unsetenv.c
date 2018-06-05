/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_unsetenv.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 12:14:04 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/05 08:56:44 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_replace_suite(t_mini *m, t_env *new)
{
	t_env	*tmp1;
	t_env	*tmp2;

	tmp1 = m->save_env;
	while (tmp1 && tmp1 != new)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	if (!tmp1)
		return ;
	new = new->next;
	if (tmp1->next != NULL)
	{
		ft_memdel((void **)&(tmp1->env));
		ft_memdel((void **)&(tmp1));
		tmp2->next = new;
	}
	else
	{
		ft_memdel((void **)&(tmp1->env));
		ft_memdel((void **)&(tmp1));
		tmp2->next = NULL;
	}
}

static void	ft_replace_env(t_mini *m, t_env *new)
{
	if (new == m->save_env)
	{
		new = new->next;
		free(m->save_env->env);
		free(m->save_env);
		m->save_env = new;
	}
	else
	{
		ft_replace_suite(m, new);
	}
}

static void	ft_del_env(t_mini *m, char *s)
{
	t_env	*new;
	int		j;

	new = m->save_env;
	while (new)
	{
		j = 0;
		while (new->env[j] == s[j] && s[j] && new->env[j])
			j++;
		while (new->env[j] != '=' && new->env[j] == s[j])
			j++;
		if (s[j] == '\0' && new->env[j] == '=')
		{
			ft_replace_env(m, new);
			break ;
		}
		new = new->next;
	}
}

void		ft_unsetenv(t_mini *m)
{
	int i;

	i = 1;
	if (!m->arg[1])
		ft_putendl("unset: not enough arguments");
	else
	{
		while (m->arg[i])
		{
			ft_del_env(m, m->arg[i]);
			i++;
		}
	}
}
