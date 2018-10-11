/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_verif_flag.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/09 10:27:35 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 10:03:43 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_verif_flag(int ac, char **av, t_opt *ret)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac && av[i][0] == '-' && av[i][1] != '\0')
	{
		j = 1;
		while (av[i][j] != '\0')
		{
			if ((ft_strchr(OPTION, av[i][j])) == NULL)
				return (ft_print_flag_error(av[i][j]));
			ret->rmaj = (av[i][j] == 'R') ? 1 : ret->rmaj;
			ret->r = (av[i][j] == 'r') ? 1 : ret->r;
			ret->a = (av[i][j] == 'a') ? 1 : ret->a;
			ret->l = (av[i][j] == 'l') ? 1 : ret->l;
			ret->t = (av[i][j] == 't') ? 1 : ret->t;
			j++;
		}
		i++;
	}
	return (i);
}

/*
** on prends les flags
** erreur si "-" seul
** -> no such file or directory
*/
