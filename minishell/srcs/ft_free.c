/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/30 16:27:37 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/06 13:24:26 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void		ft_free_lst(t_env *l)
{
	if (!l)
		return ;
	ft_free_lst(l->next);
	free(l->env);
	l->env = NULL;
	free(l);
	l = NULL;
}

void		ft_free_tab(char **t)
{
	int		i;

	i = 0;
	if (!t)
		return ;
	while (t[i])
	{
		free(t[i]);
		t[i] = NULL;
		i++;
	}
	free(t);
	t = NULL;
}

void		ft_free(t_mini *m)
{
	ft_free_lst(m->lst_env);
	ft_free_tab(m->arg);
	ft_free_lst(m->save_env);
	free(m);
	exit(0);
}
