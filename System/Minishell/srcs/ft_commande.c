/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_commande.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 17:41:59 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/31 10:41:48 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			ft_commande(t_mini *m)
{
	if ((m->cmd_path = ft_verif_path(m->bin_path, m->arg[0], 0)))
	{
		m->fk = fork();
		if (m->fk != 0)
			wait(NULL);
		else if (execve(m->cmd_path, m->arg, m->tab) == -1)
			exit(1);
	}
	else if (ft_absolute_cmd(m->arg[0]) == 1)
	{
		if (!(m->cmd_path = ft_strdup(m->arg[0])))
			return (-1);
		m->fk = fork();
		if (m->fk != 0)
			wait(NULL);
		else if (execve(m->cmd_path, m->arg, m->tab) == -1)
			exit(1);
	}
	else
		ft_putendl("command not found");
	if (m->cmd_path)
		free(m->cmd_path);
	return (1);
}
