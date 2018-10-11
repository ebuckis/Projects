/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_verif_file.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 08:40:09 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 10:03:37 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_verif_file(struct stat buf)
{
	if (errno == ENOTDIR)
		return (-3);
	if (errno == ENOENT)
		return (-2);
	if (errno == EACCES)
		return (-1);
	if (S_ISREG(buf.st_mode))
		return (1);
	if (S_ISDIR(buf.st_mode))
		return (2);
	return (0);
}

/*
** return (-3) not a directory
** return (-2) no such file or directory
** return (-1) error access
** return (0) -> ????
** return (1) fichier regulier
** return (2) dossier
*/
