/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_save_arg.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 08:36:06 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 18:18:43 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_arg		*ft_new_tfile(char *arg)
{
	t_arg		*new;
	struct stat	buf;

	new = (t_arg *)malloc(sizeof(t_arg));
	if (!new)
		return (NULL);
	lstat(arg, &buf);
	new->error = ft_verif_file(buf);
	errno = 0;
	new->arg = ft_strdup(arg);
	new->ld = NULL;
	new->next = NULL;
	return (new);
}

t_arg		*ft_save_classic_arg(void)
{
	t_arg	*lst;

	lst = ft_new_tfile(".");
	return (lst);
}

t_arg		*ft_save_arg(int i, int ac, char **av)
{
	t_arg	*lst;
	t_arg	*new;

	lst = NULL;
	while (i < ac)
	{
		if (lst == NULL)
		{
			new = ft_new_tfile(av[i]);
			if (!new)
				return (NULL);
			lst = new;
		}
		else
		{
			new->next = ft_new_tfile(av[i]);
			if (!new)
				return (NULL);
			new = new->next;
		}
		i++;
	}
	return (lst);
}
