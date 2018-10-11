/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_flag_error.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 08:08:10 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 10:02:48 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_print_flag_error(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putendl("\nusage: ls [-Rarlt] [file ...]");
	return (0);
}
