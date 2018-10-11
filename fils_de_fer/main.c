/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/09 16:53:04 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/08 17:31:30 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_chaine	*lst;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("erreur lecture fichier\n");
			return (0);
		}
		lst = ft_lecture(fd);
		if (!lst || ft_transforme(lst) == 0)
		{
			ft_putstr("fichier non conforme\n");
			return (0);
		}
		close(fd);
	}
	return (0);
}
