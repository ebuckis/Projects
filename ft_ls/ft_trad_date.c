/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_trad_date.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 14:12:28 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 16:45:21 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_diff_date(t_ldir *l)
{
	l->date_aff[0] = l->date[4];
	l->date_aff[1] = l->date[5];
	l->date_aff[2] = l->date[6];
	l->date_aff[3] = ' ';
	l->date_aff[4] = l->date[8];
	l->date_aff[5] = l->date[9];
	l->date_aff[6] = ' ';
	l->date_aff[7] = ' ';
	l->date_aff[8] = l->date[20];
	l->date_aff[9] = l->date[21];
	l->date_aff[10] = l->date[22];
	l->date_aff[11] = l->date[23];
	l->date_aff[12] = '\0';
}

void		ft_normal_date(t_ldir *l)
{
	l->date_aff[0] = l->date[4];
	l->date_aff[1] = l->date[5];
	l->date_aff[2] = l->date[6];
	l->date_aff[3] = ' ';
	l->date_aff[4] = l->date[8];
	l->date_aff[5] = l->date[9];
	l->date_aff[6] = ' ';
	l->date_aff[7] = l->date[11];
	l->date_aff[8] = l->date[12];
	l->date_aff[9] = l->date[13];
	l->date_aff[10] = l->date[14];
	l->date_aff[11] = l->date[15];
	l->date_aff[12] = '\0';
}

void		ft_trad_date(t_ldir *l)
{
	time_t	now;
	time_t	diff;

	now = time(NULL);
	diff = now - l->time;
	if (diff < 0 || diff > MOIS)
		ft_diff_date(l);
	else
		ft_normal_date(l);
}
