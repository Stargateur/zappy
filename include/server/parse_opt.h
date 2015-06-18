/*
** parse_opt.h for parse_opt in /home/plasko_a/projet/epitech/elcrypt
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Mar 15 07:44:00 2015 Antoine Plaskowski
** Last update Thu Jun 18 17:15:19 2015 Antoine Plaskowski
*/

#ifndef		PARSE_OPT_H_
# define	PARSE_OPT_H_

# include	<stdbool.h>

typedef	struct	s_opt
{
  char		*p;
  char		*x;
  char		*y;
  char		*c;
  char		*t;
}		t_opt;

bool		parse_opt(char * const * const argv, int const argc,
			  t_opt *opt);
bool		show_opt(t_opt const * const opt);

#endif		/* !PARSE_OPT_H_ */
