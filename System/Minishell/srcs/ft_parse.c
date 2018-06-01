/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/30 18:03:35 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/31 13:12:41 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_parse(char *line)
{
	char	**arg;
	char	*s;

	arg = NULL;
	s = NULL;
	s = ft_whitespace(line);
	if (s == NULL)
		return (NULL);
	arg = ft_strsplit(s, ' ');
	free(line);
	free(s);
	return (arg);
}
