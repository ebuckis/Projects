/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 10:26:07 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 17:51:35 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_free_tmp(t_mini *m)
{
	ft_free_lst(m->lst_env);
	ft_free_tab(m->arg);
}

int			main(int argc, char **argv, char **env)
{
	t_mini	*m;
	char	*line;

	m = (t_mini *)malloc(sizeof(t_mini));
	m->save_env = ft_cpy_env(env);
	while (1)
	{
		m->lst_env = ft_save_env(m->save_env);
		ft_putstr(ft_search_env(m->save_env, "PWD="));
		ft_putstr(" : ");
		get_next_line(0, &line);
		m->arg = ft_parse(line);
		if (m->arg)
		{
			ft_transforme_arg(m);
			ft_lancement(m, m->save_env);
		}
		ft_free_tmp(m);
		free(line);
	}
	ft_free(m);
}
