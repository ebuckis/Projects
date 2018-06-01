/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 08:17:39 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 08:17:41 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*s;

	s = (t_list *)malloc(sizeof(t_list));
	if (!s)
		return (NULL);
	if (!content)
	{
		s->content = NULL;
		s->content_size = 0;
	}
	else
	{
		s->content = malloc(sizeof(void) * content_size);
		if (!(s->content))
			return (NULL);
		s->content_size = content_size;
		ft_memcpy(s->content, content, content_size);
	}
	s->next = NULL;
	return (s);
}
