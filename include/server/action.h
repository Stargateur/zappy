/*
** action.h for action in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Jun 29 18:18:24 2015 Antoine Plaskowski
** Last update Sat Jul  4 18:52:01 2015 Antoine Plaskowski
*/

#ifndef		ACTION_H_
# define	ACTION_H_

# include	<stdbool.h>

typedef	struct	s_action	t_action;

# include	"node.h"
# include	"parser.h"
# include	"player.h"
# include	"time_utils.h"
# include	"game.h"

struct		s_action
{
  t_node	node;
  char		*str;
  char		*arg;
  t_cmd		*cmd;
  t_time	time;
};

bool		show_action(t_action *action);
bool		do_action(t_game *game);
t_action	*delete_action(t_action *action);

#endif		/* !ACTION_H_ */
