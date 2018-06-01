/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_search_env.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/30 10:21:50 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/30 11:27:57 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_search_env(t_env *l, char *s)
{
	t_env	*new;
	int		n;

	if (!s || !l)
		return (NULL);
	n = ft_strlen(s);
	new = l;
	while (new && ft_strncmp(new->env, s, n) != 0)
		new = new->next;
	if (!new)
		return (NULL);
	return (new->env + n);
}
