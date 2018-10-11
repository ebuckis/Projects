/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_verif_path.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/29 17:46:02 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/30 12:17:36 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			ft_absolute_cmd(char *cmd)
{
	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
			return (1);
		else
			return (-1);
	}
	else
		return (-1);
}

char		*ft_verif_path(char **path, char *cmd, int i)
{
	char	*str;

	if (!path)
		return (NULL);
	if (!path[i])
		return (NULL);
	if (!(str = ft_strjoin(path[i], cmd)))
		return (NULL);
	if (access(str, F_OK) == 0)
	{
		if (access(str, X_OK) == 0)
			return (str);
		else
		{
			free(str);
			return (NULL);
		}
	}
	else
	{
		i++;
		free(str);
		return (ft_verif_path(path, cmd, i));
	}
}
