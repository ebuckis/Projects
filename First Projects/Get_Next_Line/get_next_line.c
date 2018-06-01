/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 08:39:05 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 10:23:45 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

static char	**ft_read_fichier(char *buf, char **s)
{
	char *str;

	if (!*s)
		*s = ft_strdup(buf);
	else
	{
		str = ft_strdup(*s);
		ft_strdel(s);
		*s = ft_strjoin(str, buf);
		ft_strdel(&str);
	}
	return (s);
}

static int	ft_strchr_index(const char *s, int c)
{
	int i;

	i = 0;
	if (c == '\0')
		return (ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		else
			i++;
	}
	return (-1);
}

static int	ft_copy_s(char **s, char **line)
{
	int		i;
	char	*temp;

	i = ft_strchr_index(*s, '\n');
	if (i == -1)
		i = ft_strlen(*s);
	temp = ft_strdup(*s);
	*line = ft_strsub(temp, 0, i);
	ft_strdel(s);
	if (ft_strlen(temp) == 0)
	{
		ft_strdel(&temp);
		ft_strdel(s);
		return (0);
	}
	*s = ft_strsub(temp, i + 1, (ft_strlen(temp) - (i + 1)));
	ft_strdel(&temp);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			n;
	char		buf[BUFF_SIZE + 1];
	static char *s = NULL;

	if ((n = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[n] = '\0';
		s = *ft_read_fichier(buf, &s);
		if (ft_strchr_index(s, '\n') == -1)
			return (get_next_line(fd, line));
	}
	if (n == -1)
		return (-1);
	buf[0] = '\0';
	s = *ft_read_fichier(buf, &s);
	return (ft_copy_s(&s, line));
}
