/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strclr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 08:23:32 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 08:23:34 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int n;

	if (s)
	{
		n = ft_strlen(s);
		ft_bzero(s, n);
	}
}
