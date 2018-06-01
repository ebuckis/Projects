/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 08:17:56 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 11:47:56 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	s = malloc(sizeof(void) * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
