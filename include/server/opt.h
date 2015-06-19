/*
** opt.h for opt in /home/plasko_a/projet/epitech/elcrypt
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Mar 15 07:44:00 2015 Antoine Plaskowski
** Last update Fri Jun 19 15:34:56 2015 Antoine Plaskowski
*/

#ifndef		OPT_H_
# define	OPT_H_

# include	<stdbool.h>

typedef	struct	s_opt
{
  char const	*p;
  char const	*x;
  char const	*y;
  char const	*c;
  char const	*t;
  char * const	*team;
}		t_opt;

extern t_opt	opt;

bool		get_opt(char * const * const argv, int const argc);
bool		show_opt(void);

#endif		/* !OPT_H_ */
