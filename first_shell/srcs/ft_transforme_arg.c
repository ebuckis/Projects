/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_transforme_arg.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 16:42:15 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/31 10:23:18 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_trans_tild(t_mini *m, int i)
{
	char	*path;
	char	*var;
	char	*s;

	s = m->arg[i];
	s++;
	var = ft_search_env(m->save_env, "HOME=");
	if (!var)
		return ;
	if (!(path = ft_strdup(var)))
		return ;
	if (ft_strlen(s) > 1)
	{
		if (!(path = ft_strjoin_del(path, "/")))
			return ;
		if (!(path = ft_strjoin_del(path, s + 1)))
			return ;
	}
	free(m->arg[i]);
	m->arg[i] = path;
}

static void	ft_trans_dollar(t_mini *m, int i)
{
	char	*s;
	char	*var;

	s = m->arg[i];
	s++;
	if ((var = ft_search_env(m->save_env, s)))
	{
		free(m->arg[i]);
		m->arg[i] = ft_strdup(var + 1);
		if (!m->arg[i])
			return ;
	}
}

void		ft_transforme_arg(t_mini *m)
{
	int		i;

	i = 0;
	while (m->arg[i])
	{
		if (m->arg[i][0] == '$')
		{
			ft_trans_dollar(m, i);
		}
		if (m->arg[i][0] == '~')
		{
			ft_trans_tild(m, i);
		}
		i++;
	}
}
