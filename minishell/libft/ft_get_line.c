/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_get_line.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/05 11:02:05 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/05 11:44:51 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	free_lst(t_list *l)
{
	if (!l)
		return ;
	free_lst(l->content);
	free(l->content);
	l->content = NULL;
	free(l);
	l = NULL;
}

static int	ft_read_file(t_list *lst, int *ret)
{
	char	tmp[BUFF_SIZE_GNL + 1];
	char	*store;

	store = lst->content;
	*ret = read(lst->content_size, tmp, BUFF_SIZE_GNL);
	tmp[*ret] = '\0';
	if (!(lst->content = ft_strjoin(store, tmp)))
		return (0);
	ft_strdel(&store);
	return (1);
}

int			ft_get_line(const int fd, char **line)
{
	t_list	*lst;
	char	*file;
	int		ret;

	lst = ft_lstnew(NULL, 0);
	ret = 1;
	if (!line || fd < 0 || !lst)
		return (-1);
	while (ret > 0 && (ft_read_file(lst, &ret)))
		if ((file = ft_strchr(lst->content, '\n')) != NULL)
		{
			*file = '\0';
			if (!(*line = ft_strdup(lst->content)))
				return (-1);
			ft_memmove(lst->content, file + 1, ft_strlen(file + 1) + 1);
			free_lst(lst);
			return (1);
		}
	ft_strdel(&file);
	return (ret);
}
