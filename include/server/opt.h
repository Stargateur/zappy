/*
** opt.h for opt in /home/plasko_a/projet/epitech/elcrypt
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Mar 15 07:44:00 2015 Antoine Plaskowski
** Last update Tue Jun 30 17:20:02 2015 Antoine Plaskowski
*/

#ifndef		OPT_H_
# define	OPT_H_

# include	<stdbool.h>

typedef	struct	s_opt	t_opt;
struct		s_opt
{
  char const	*p;
  size_t	x;
  size_t	y;
  size_t	c;
  size_t	t;
  char * const	*team;
};

extern t_opt	opt;

bool		get_opt(char * const * const argv, int const argc);
bool		show_opt(void);

#endif		/* !OPT_H_ */
