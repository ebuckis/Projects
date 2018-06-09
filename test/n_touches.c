/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   n_touches.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/08 09:56:37 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/08 10:16:24by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <curses.h>
#include <term.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_myoutc(int c)
{
	ft_putchar((char)(c));
	return (1);
}

int     voir_touche()
{
	char     buffer[3];
	char    *res;
	int		x;
	int		y;
 
	x = 0;
	y = 0;
	while (1)
	{
		read(0, buffer, 3);
		ft_putchar('c');
	//	printf("|%d|  |%d|  |%d|\n", buffer[0], buffer[1], buffer[2]);
		if (buffer[0] == 99)
		{
			if ((res = tgetstr("cl", NULL)) == NULL)
			{
				return (-1);
			}
			tputs(res, 0, &ft_myoutc);
		}
		else if (buffer[0] == 27 && buffer[1] == 91)
		{
			res = tgetstr("cm", NULL);
			/*
			** On utilise la fonction tgoto, qui va retourner une série d'instructions (sous forme de chaine de caractère)
			** afin de déplacer le curseur jusqu'à l'endroit voulu.
			*/
			if (buffer[2] == 65)//haut
			{
				tputs(tgoto(res, x, y--), 1, ft_myoutc);
			}
			else if (buffer[2] == 66)//bas
			{
				tputs(tgoto(res, x, y++), 1, ft_myoutc);
			}
			else if (buffer[2] == 67)//droit
			{
				tputs(tgoto(res, x++, y), 1, ft_myoutc);
			}
			else if (buffer[2] == 68)//gauche
			{
				tputs(tgoto(res, x--, y), 1, ft_myoutc);
			}
		}
		else if (buffer[0] == 4)
		{
			printf("Ctlr+d, on quitte !\n");
			return (0);
		}
		buffer[0] = '\0';
		buffer[1] = '\0';
		buffer[2] = '\0';
	}
	return (0);
}

int              main(int ac, char **av, char **env)
{
	char           *name_term;
	struct termios term;
	
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	// remplis la structure termios des possibilités du terminal.
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;//on lit un seul char
	term.c_cc[VTIME] = 0;//on refresh instant'
	// On applique les changements :
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	voir_touche();
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
return (0);
}
 