/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_each_path.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 17:53:10 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/31 14:03:01 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_each_path(t_env *lst)
{
	char	**path;
	t_env	*new;
	int		n;

	if (!lst)
		return (NULL);
	new = lst;
	while (new && ft_strncmp(new->env, "PATH=", 5) != 0)
		new = new->next;
	if (!new)
		return (NULL);
	path = ft_strsplit(new->env + 5, ':');
	n = 0;
	while (path[n])
	{
		path[n] = ft_strjoin_del(path[n], "/");
		n++;
	}
	return (path);
}
