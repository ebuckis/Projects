/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cd.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 12:13:27 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/31 10:12:21 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			ft_chdir(t_mini *m, char *s, t_env *l)
{
	char	*new_path;
	char	*old_path;

	new_path = NULL;
	old_path = NULL;
	old_path = getcwd(old_path, 1024);
	if (!old_path)
		return (0);
	if (chdir(s) < 0)
	{
		free(old_path);
		return (-1);
	}
	ft_get_oldpwd(m, old_path, l);
	new_path = getcwd(new_path, 1024);
	if (!new_path)
		return (0);
	ft_change_pwd(m, new_path, l);
	return (1);
}

int			ft_cd2(t_mini *m, t_env *l)
{
	char	*s;

	if (m->arg[1])
	{
		if (m->arg[2])
			return (-2);
		if (ft_strcmp(m->arg[1], "-") == 0)
		{
			s = ft_search_env(l, "OLDPWD=");
			if (ft_chdir(m, s, l) < 0)
				return (-1);
		}
		else if (ft_chdir(m, m->arg[1], l) < 0)
			return (-1);
	}
	else
		ft_chdir(m, ft_search_env(l, "HOME="), l);
	return (0);
}

void		ft_cd(t_mini *m, t_env *l)
{
	int		n;

	n = ft_cd2(m, l);
	if (n < 0)
	{
		if (n == -1)
			ft_putstr_fd("cd : no such file or diredtory: ", 2);
		else if (n == -2)
			ft_putstr_fd(" cd : string not in pwd: ", 2);
		ft_putendl_fd(m->arg[1], 2);
	}
}
