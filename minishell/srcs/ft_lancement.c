/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lancement.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/30 11:45:24 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 17:05:24 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_convert(t_env *l)
{
	char	**t;
	t_env	*new;
	int		i;

	i = 0;
	new = l;
	while (new)
	{
		new = new->next;
		i++;
	}
	if (!(t = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	new = l;
	i = 0;
	while (new)
	{
		if (!(t[i] = ft_strdup(new->env)))
			return (NULL);
		new = new->next;
		i++;
	}
	t[i] = NULL;
	return (t);
}

static int	ft_verif_builtin(t_mini *m, t_env *l)
{
	if (ft_strcmp(m->arg[0], "cd") == 0)
		ft_cd(m, l);
	else if (ft_strcmp(m->arg[0], "echo") == 0)
		ft_echo(m);
	else if (ft_strcmp(m->arg[0], "setenv") == 0)
		ft_setenv(m, l);
	else if (ft_strcmp(m->arg[0], "unsetenv") == 0)
		ft_unsetenv(m);
	else if (ft_strcmp(m->arg[0], "env") == 0)
		ft_env(m);
	else
		return (0);
	return (1);
}

int			ft_lancement(t_mini *m, t_env *l)
{
	int		i;

	if (ft_strcmp("exit", m->arg[0]) == 0)
		ft_free(m);
	if (ft_verif_builtin(m, l) == 0)
	{
		m->bin_path = ft_each_path(l);
		m->tab = ft_convert(l);
		ft_commande(m);
		ft_free_tab(m->bin_path);
		ft_free_tab(m->tab);
	}
	return (1);
}
