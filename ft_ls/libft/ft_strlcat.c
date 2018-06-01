/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 08:25:25 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 08:25:26 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			j;
	unsigned int	temp;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	temp = i;
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	j = 0;
	while (src[j])
		j++;
	dst[i] = '\0';
	if (temp < size)
		return (j + temp);
	else
		return (j + size);
}
