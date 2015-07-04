/*
** parser.h for parser in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jun 18 18:37:14 2015 Antoine Plaskowski
** Last update Sat Jul  4 23:00:16 2015 Antoine Plaskowski
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

# include	"game.h"
# include	"player.h"
# include	"action.h"

struct		s_cmd
{
  char const	*cmd;
  bool		(*fct)(t_game *game, t_player *player, char *arg);
  t_tcmd	type;
  size_t	time;
  size_t	len_cmd;
};

t_action	*parser(char *str, size_t const t);

#endif		/* !PARSER_H_ */
