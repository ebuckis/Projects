/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 12:44:06 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 16:35:03 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define OPTION "Ralrt"
# define MOIS 15778800
# include <stdlib.h>
# include <time.h>
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include "libft/libft.h"

typedef struct		s_ldir
{
	char			*path;
	char			*file;
	char			droit[11];
	int				link;
	int				link_l;
	char			*usr;
	int				usr_l;
	char			*group;
	int				group_l;
	int				size;
	int				size_l;
	time_t			time;
	char			*date;
	char			date_aff[13];
	char			l_symb[1024];
	int				date_type;
	int				error;
	unsigned long	block;
	int				major;
	int				major_l;
	int				minor;
	int				minor_l;
	struct s_ldir	*under;
	struct s_ldir	*next;
}					t_ldir;
typedef struct		s_arg
{
	int				error;
	char			*arg;
	struct s_ldir	*ld;
	struct s_arg	*next;
}					t_arg;
typedef struct		s_opt
{
	int				rmaj;
	int				r;
	int				l;
	int				a;
	int				t;
}					t_opt;
typedef struct		s_tmp
{
	int				link;
	int				usr;
	int				grp;
	int				size;
	int				major;
	int				minor;
}					t_tmp;
/*
** verification des flags
** error si flag incorrect
** uasge et arret de la fonction
*/
int					ft_verif_flag(int ac, char **av, t_opt *ret);
int					ft_print_flag_error(char c);
/*
** verif des argument
** et save dans list t_arg
*/
int					ft_verif_arg(int ac, char **av, int i, t_opt ret);
t_arg				*ft_save_arg(int i, int ac, char **av);
t_arg				*ft_save_classic_arg(void);
int					ft_verif_file(struct stat buf);
/*
** on boucle sur les arg
*/
int					ft_lancement(t_arg *lst, t_opt ret);
t_ldir				*ft_save_ldir(t_arg *lst, t_opt ret);
/*
** creation de la liste ld
*/
t_ldir				*ft_new_ldir(int error, char *s, t_opt ret);
t_ldir				*ft_init_first(t_ldir *ld, char *str, t_opt ret);
t_ldir				*ft_add_ldir(t_ldir *ld, char *str, t_opt ret);
/*
** on chope les infos
*/
void				ft_init_ldir(t_ldir *ld);
t_ldir				*ft_read_dir(char *arg, t_opt ret, DIR *dir, t_ldir *ld);
int					ft_search_info(t_ldir *ld, char *s, t_opt ret);
/*
** fonctions autres
*/
int					ft_int_len(int n);
void				ft_trad_date(t_ldir *l);
int					ft_condition_dir(t_opt ret, char *file);
/*
** recursive
*/
t_ldir				*ft_recursive(char *s, char *file, t_opt ret);
/*
** Sort
*/
t_arg				*ft_sort_all(t_arg *lst, t_opt ret);
int					ft_cmp_ret(t_arg *l1, t_arg *l2, t_opt ret);
int					ft_cmp_ldir(t_ldir *l1, t_ldir *l2, t_opt ret);
t_ldir				*ft_sort_ldir(t_ldir *ld, t_opt ret);
t_arg				*ft_swap_arg(t_arg *l1, t_arg *l2);
t_ldir				*ft_swap_ldir(t_ldir *l1, t_ldir *l2);
/*
** on recupere le total
*/
void				ft_total_block(t_ldir *ld);
/*
** Impression
*/
void				ft_print_all(t_arg *lst, t_opt ret);
void				ft_print_ld(t_ldir *ld, t_opt ret);
void				ft_print_oth(t_arg *lst, t_ldir *tmp, int i);
void				ft_print_under(t_ldir *ld, t_opt ret);
void				ft_print_info(t_ldir *ld);
/*
** FREEEEEEEE like a river
*/
void				ft_free_all(t_arg *lst);
#endif
