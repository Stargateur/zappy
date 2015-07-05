/*
** option.h for option in /home/plasko_a/projet/epitech/elcrypt
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Mar 15 07:44:00 2015 Antoine Plaskowski
** Last update Sun Jul  5 18:27:25 2015 Antoine Plaskowski
*/

#ifndef		OPTION_H_
# define	OPTION_H_

# include	<stdbool.h>

typedef	struct	s_option	t_option;
struct		s_option
{
  char		*p;
  char		*n;
  size_t	x;
  size_t	y;
  size_t	c;
  size_t	t;
  bool		g;
  char		**team;
};

bool		get_option(t_option *option, char **argv,
			   int const argc);
bool		show_option(t_option *option);

#endif		/* !OPTION_H_ */
