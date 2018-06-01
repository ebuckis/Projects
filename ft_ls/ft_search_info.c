/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_search_info.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/14 13:19:37 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/29 15:50:43 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_sticky_size(struct stat buf, t_ldir *ld)
{
	if (ld->droit[0] == 'c' || ld->droit[0] == 'b')
	{
		ld->major = major(buf.st_rdev);
		ld->minor = minor(buf.st_rdev);
		ld->major_l = ft_int_len(ld->major);
		ld->minor_l = ft_int_len(ld->minor);
		ld->size = -1;
	}
	else
	{
		ld->size = buf.st_size;
		ld->size_l = ft_int_len(ld->size);
		ld->minor = -1;
		ld->major = -1;
	}
}

static void	ft_info_suite(struct stat buf, t_ldir *ld)
{
	struct passwd	*uid;
	struct group	*pid;
	int				retour;

	uid = getpwuid(buf.st_uid);
	pid = getgrgid(buf.st_gid);
	ld->usr = (uid == NULL) ? ft_itoa(buf.st_uid) : ft_strdup(uid->pw_name);
	ld->group = (pid == NULL) ? ft_itoa(buf.st_gid) : ft_strdup(pid->gr_name);
	ld->usr_l = ft_strlen(ld->usr);
	ld->group_l = ft_strlen(ld->group);
	ft_sticky_size(buf, ld);
	ld->link = buf.st_nlink;
	ld->link_l = ft_int_len(ld->link);
	ld->block = buf.st_blocks;
	if (ld->droit[0] == 'l')
	{
		retour = readlink(ld->path, ld->l_symb, 1024);
		ld->l_symb[retour] = '\0';
	}
	else
		ft_bzero(ld->l_symb, 1024);
}

static void	ft_all_info(struct stat buf, t_ldir *ld)
{
	ld->droit[0] = S_ISREG(buf.st_mode) ? '-' : 0;
	ld->droit[0] = S_ISDIR(buf.st_mode) ? 'd' : ld->droit[0];
	ld->droit[0] = S_ISCHR(buf.st_mode) ? 'c' : ld->droit[0];
	ld->droit[0] = S_ISBLK(buf.st_mode) ? 'b' : ld->droit[0];
	ld->droit[0] = S_ISFIFO(buf.st_mode) ? 'p' : ld->droit[0];
	ld->droit[0] = S_ISLNK(buf.st_mode) ? 'l' : ld->droit[0];
	ld->droit[0] = S_ISSOCK(buf.st_mode) ? 's' : ld->droit[0];
	ld->droit[1] = (buf.st_mode & S_IRUSR) ? 'r' : '-';
	ld->droit[2] = (buf.st_mode & S_IWUSR) ? 'w' : '-';
	ld->droit[3] = (buf.st_mode & S_IXUSR) ? 'x' : '-';
	ld->droit[4] = (buf.st_mode & S_IRGRP) ? 'r' : '-';
	ld->droit[5] = (buf.st_mode & S_IWGRP) ? 'w' : '-';
	ld->droit[6] = (buf.st_mode & S_IXGRP) ? 'x' : '-';
	ld->droit[7] = (buf.st_mode & S_IROTH) ? 'r' : '-';
	ld->droit[8] = (buf.st_mode & S_IWOTH) ? 'w' : '-';
	ld->droit[9] = (buf.st_mode & S_IXOTH) ? 'x' : '-';
	ld->droit[3] = (buf.st_mode & S_ISUID) ? 'S' : ld->droit[3];
	ld->droit[6] = (buf.st_mode & S_ISGID) ? 'S' : ld->droit[6];
	if (buf.st_mode & S_ISVTX)
		ld->droit[9] = (ld->droit[3] == 'x') ? 't' : 'T';
	ld->droit[10] = '\0';
}

static void	ft_search_date(struct stat buf, t_ldir *ld)
{
	ld->time = buf.st_mtime;
	ld->date = ctime(&ld->time);
	ft_trad_date(ld);
	ft_all_info(buf, ld);
	ft_info_suite(buf, ld);
}

int			ft_search_info(t_ldir *ld, char *s, t_opt ret)
{
	struct stat		buf;

	errno = 0;
	lstat(s, &buf);
	if (ret.l == 1)
		ret.l++;
	ld->error = ft_verif_file(buf);
	if (ld->error < 0)
	{
		return (0);
	}
	ft_search_date(buf, ld);
	return (1);
}
