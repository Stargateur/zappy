/*
** parser.h for parser in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jun 18 18:37:14 2015 Antoine Plaskowski
** Last update Fri Jul  3 21:03:02 2015 Antoine Plaskowski
*/

#ifndef		PARSER_H_
# define	PARSER_H_

# include	<stddef.h>

typedef	struct	s_cmd	t_cmd;
typedef	enum	e_tcmd
  {
    AVANCE,
    DROITE,
    GAUCHE,
    VOIR,
    INVENTAIRE,
    PREND,
    POSE,
    EXPULSE,
    BROADCAST,
    INCANTATION,
    FORK,
    CONNECT_NBR
  }		t_tcmd;

# include	"action.h"

struct		s_cmd
{
  char const	*cmd;
  t_tcmd	type;
  size_t	time;
  size_t	len_cmd;
};

t_action	*parser(char *str, size_t const t);

#endif		/* !PARSER_H_ */
