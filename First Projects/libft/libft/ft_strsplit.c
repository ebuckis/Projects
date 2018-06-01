/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 08:27:54 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 08:27:56 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int		cpt_mot(const char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static int		*cpt_lgmot(char const *s, char c, int *lgmot)
{
	int		i;
	int		j;
	int		boucle;

	i = 0;
	boucle = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			j++;
		}
		lgmot[boucle] = j + 1;
		boucle++;
	}
	return (lgmot);
}

static char		**ft_cpy(const char *s, char c, char **sortie, int len)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			sortie[j][k] = s[i];
			k++;
			i++;
		}
		if (k != 0)
			sortie[j][k] = '\0';
		j++;
	}
	sortie[len] = NULL;
	return (sortie);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**sortie;
	int		*lgmot;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (0);
	j = cpt_mot(s, c);
	sortie = (char **)malloc(sizeof(char *) * j);
	lgmot = (int *)malloc(sizeof(int) * j);
	if (!sortie || !lgmot)
		return (0);
	lgmot = cpt_lgmot(s, c, lgmot);
	while (i < j)
	{
		sortie[i] = (char *)malloc(sizeof(char) * (lgmot[i]));
		if (!sortie[i])
			return (0);
		i++;
	}
	sortie = ft_cpy(s, c, sortie, j);
	return (sortie);
}
