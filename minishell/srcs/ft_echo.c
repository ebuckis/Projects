/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_echo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 12:13:51 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/01 09:54:56 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_verif_n(char *s)
{
	int		i;

	i = 1;
	if (!s)
		return (0);
	if (s[0] != '-')
		return (0);
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	if (i == 1)
		return (0);
	return (1);
}

void		ft_echo(t_mini *m)
{
	int		i;
	int		j;

	i = 1;
	if (m->arg[1])
	{
		while (ft_verif_n(m->arg[i]))
		{
			i++;
		}
		j = i;
		while (m->arg[j])
		{
			if (i != j)
				ft_putstr(" ");
			ft_putstr(m->arg[j]);
			j++;
		}
	}
	if (i == 1)
		ft_putchar('\n');
}
