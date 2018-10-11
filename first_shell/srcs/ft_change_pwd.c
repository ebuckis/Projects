/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_change_pwd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/30 10:32:13 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/30 15:36:20 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void		ft_change_pwd(t_mini *m, char *s, t_env *l)
{
	t_env	*new;

	new = l;
	while (new && ft_strncmp(new->env, "PWD=", 4) != 0)
		new = new->next;
	if (!new)
		return ;
	free(new->env);
	if (!(new->env = ft_strdup("PWD=")))
		return ;
	if (!(new->env = ft_strjoin_del(new->env, s)))
		return ;
	free(s);
}

void		ft_get_oldpwd(t_mini *m, char *s, t_env *l)
{
	t_env	*new;

	new = l;
	while (new && ft_strncmp(new->env, "OLDPWD=", 7) != 0)
		new = new->next;
	if (!new)
		return ;
	free(new->env);
	if (!(new->env = ft_strdup("OLDPWD=")))
		return ;
	if (!(new->env =
		ft_strjoin_del(new->env, s)))
		return ;
	free(s);
}
