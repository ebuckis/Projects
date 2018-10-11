/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parser.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 15:16:59 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 14:33:43 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_antislash(t_parse *p, char *s)
{
	if (s[p->i + 1] == '\0')
	{
		ft_putstr(" > ");
		s = ft_suite_line(p, s, 0);
	}
	else
	{
		p->i++;
		ft_end_while(p, s);
	}
	return (s);
}

char		*ft_parse_dquote(t_parse *p, char *s)
{
	p->i++;
	while (1)
	{
		if (s[p->i] == 92)
		{
			if (s[p->i + 1] == 96 || s[p->i + 1] == '$'
				|| s[p->i + 1] == 92 || s[p->i + 1] == 34)
				p->i++;
			ft_end_while(p, s);
		}
		else if (s[p->i] == 34)
		{
			p->i++;
			return (s);
		}
		else if (s[p->i] != '\0')
			ft_end_while(p, s);
		else
		{
			s = ft_suite_line(p, s, 1);
		}
	}
	return (s);
}

char		*ft_parse_quote(t_parse *p, char *s)
{
	p->i++;
	while (1)
	{
		if (s[p->i] == 39)
		{
			p->i++;
			return (s);
		}
		else if (s[p->i] != '\0')
		{
			ft_end_while(p, s);
		}
		while (s[p->i] == '\0')
		{
			ft_putstr("quote> ");
			s = ft_suite_line(p, s, 1);
		}
	}
	return (s);
}

char		*ft_str_parser(char *s)
{
	t_parse	*p;

	p = ft_init_parse(s);
	while (s[p->i])
	{
		if (s[p->i] == 92)
			s = ft_antislash(p, s);
		else if (s[p->i] == 34)
			s = ft_parse_dquote(p, s);
		else if (s[p->i] == 39)
			s = ft_parse_quote(p, s);
		else if (s[p->i] == ' ' || s[p->i] == '\t'
			|| s[p->i] == '\n' || s[p->i] == '\r' || s[p->i] == '\v')
		{
			p->str[p->j] = -1;
			p->i++;
			p->j++;
		}
		else
			ft_end_while(p, s);
	}
	free(s);
	s = p->str;
	free(p);
	return (s);
}

char		**ft_parser(char *s)
{
	char	**arg;

	arg = NULL;
	if (s)
	{
		s = ft_str_parser(s);
		arg = ft_strsplit(s, -1);
		free(s);
	}
	return (arg);
}

/*
** ne pas envoyer un argv a ft_parser
** s est free
*/
