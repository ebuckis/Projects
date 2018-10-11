/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/23 09:03:33 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/04 17:00:58 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PROMPT "---> : "
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

/*
** utilisation de GNL pour lecture des entrees
**
** variable d'environnement PATH, strchr "/", puis split ":"
** pour obtenir les != path des fonctions
**
** verif avec la fonction access du chemin
**
** creation d'un processus fils en boucle pour les fonctions a lancer
**
** "$>" au debut de chaque fonction
**
** echo, cd, setenv, unsetenv, env, exit a mettre en place, (exit pas a coder)
**
** http://i.paysdu42.fr/?page=minishell.c
*/

typedef struct		s_env
{
	char			*env;
	struct s_env	*next;
}					t_env;
typedef struct		s_mini
{
	char			**bin_path;
	char			**arg;
	char			**tab;
	char			*cmd_path;
	int				fk;
	t_env			*lst_env;
	t_env			*save_env;
}					t_mini;

t_env				*ft_save_env(t_env *lst);
t_env				*ft_cpy_env(char **env);
void				ft_transforme_arg(t_mini *m);
char				**ft_parse(char *line);
char				*ft_whitespace(char *s);
int					ft_lancement(t_mini *m, t_env *l);
char				*ft_verif_path(char **path, char *cmd, int i);
char				**ft_each_path(t_env *lst);
int					ft_absolute_cmd(char *cmd);
int					ft_commande(t_mini *m);
char				*ft_search_env(t_env *l, char *s);
void				ft_cd(t_mini *m, t_env *l);
void				ft_change_pwd(t_mini *m, char *s, t_env *l);
void				ft_get_oldpwd(t_mini *m, char *s, t_env *l);
void				ft_echo(t_mini *m);
void				ft_env(t_mini *m);
void				ft_setenv(t_mini *m, t_env *l);
t_env				*ft_add_env(t_env *l, char *name, char *val);
void				ft_unsetenv(t_mini *m);
t_env				*ft_malloc_env(char *s);
void				ft_print_env(t_env *l);
void				ft_free(t_mini *m);
void				ft_free_lst(t_env *l);
void				ft_free_tab(char **t);
#endif
