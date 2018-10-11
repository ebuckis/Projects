/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_env.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 12:13:56 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/31 14:05:33 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void		ft_modif_arg(t_mini *m, int i)
{
	int		j;

	j = 0;
	while (m->arg[j + i])
	{
		ft_strclr(m->arg[j]);
		free(m->arg[j]);
		m->arg[j] = ft_strdup(m->arg[j + i]);
		j++;
	}
	while (m->arg[j])
	{
		free(m->arg[j]);
		m->arg[j] = NULL;
		j++;
	}
}

void		ft_env(t_mini *m)
{
	int		i;
	char	**tab;

	i = 1;
	if (!m->arg[1])
		ft_print_env(m->lst_env);
	if (m->arg[1] && ft_strcmp(m->arg[1], "-i") == 0)
	{
		i++;
		ft_free_lst(m->lst_env);
		m->lst_env = NULL;
	}
	while (m->arg[i] && ft_strchr(m->arg[i], '=') != NULL)
	{
		if (m->arg[i][0] == '=')
			break ;
		tab = ft_strsplit(m->arg[i], '=');
		m->lst_env = ft_add_env(m->lst_env, tab[0], tab[1]);
		ft_free_tab(tab);
		i++;
	}
	if (!m->arg[i])
		return ;
	ft_modif_arg(m, i);
	ft_lancement(m, m->lst_env);
}
