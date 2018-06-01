/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_save_env.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 11:04:40 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/30 17:46:08 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

t_env		*ft_malloc_env(char *s)
{
	t_env	*l;

	l = (t_env *)malloc(sizeof(t_env));
	if (!l)
		return (NULL);
	l->env = strdup(s);
	if (!l->env)
		return (NULL);
	l->next = NULL;
	return (l);
}

t_env		*ft_cpy_env(char **env)
{
	t_env	*lst;
	t_env	*new;
	int		i;

	lst = NULL;
	i = 0;
	while (env[i])
	{
		if (lst == NULL)
		{
			if (!(lst = ft_malloc_env(env[i])))
				return (NULL);
			new = lst;
		}
		else
		{
			if (!(new->next = ft_malloc_env(env[i])))
				return (NULL);
			new = new->next;
		}
		i++;
	}
	return (lst);
}

t_env		*ft_save_env(t_env *lst)
{
	t_env	*save;
	t_env	*tmp;
	t_env	*new;

	save = NULL;
	tmp = lst;
	while (tmp)
	{
		if (save == NULL)
		{
			if (!(save = ft_malloc_env(tmp->env)))
				return (NULL);
			new = save;
		}
		else
		{
			if (!(new->next = ft_malloc_env(tmp->env)))
				return (NULL);
			new = new->next;
		}
		tmp = tmp->next;
	}
	return (save);
}
