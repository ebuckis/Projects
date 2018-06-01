/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 08:16:42 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/26 14:53:07 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *cpy;

	cpy = *alst;
	while (cpy)
	{
		del(cpy->content, cpy->content_size);
		free(cpy);
		cpy = cpy->next;
	}
	*alst = NULL;
}
