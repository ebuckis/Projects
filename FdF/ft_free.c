/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/08 10:01:33 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 17:05:50 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_list(t_chaine *lst)
{
	t_chaine	*del;
	t_chaine	*temp;
	int			i;

	if (lst != NULL)
	{
		del = lst;
		while (del)
		{
			temp = del;
			i = 0;
			while (i < del->x)
			{
				free(del->l_split[i]);
				i++;
			}
			free(del->l_split);
			del = del->next;
			free(temp);
		}
		lst = NULL;
	}
}

void	ft_free_tab(int **tab, int x)
{
	int i;

	i = 0;
	if (tab != NULL)
	{
		while (i < x)
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}
