/*
** parser.h for parser in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jun 18 18:37:14 2015 Antoine Plaskowski
** Last update Mon Jun 29 22:14:28 2015 Antoine Plaskowski
*/

#ifndef		PARSER_H_
# define	PARSER_H_

typedef	struct	s_cmd	t_cmd;

# include	<stddef.h>
# include	"action.h"

enum		e_tcmd
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
  };
typedef	enum	e_tcmd	t_tcmd;

struct		s_cmd
{
  char const	*cmd;
  t_tcmd	type;
  size_t	time;
};

t_action	*parser(char *str);

#endif		/* !PARSER_H_ */
