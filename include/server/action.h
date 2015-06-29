/*
** action.h for action in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Jun 29 18:18:24 2015 Antoine Plaskowski
** Last update Mon Jun 29 20:00:06 2015 Antoine Plaskowski
*/

#ifndef		ACTION_H_
# define	ACTION_H_

typedef	struct	s_action	t_action;

# include	"node.h"
# include	"parser.h"

struct		s_action
{
  t_node	node;
  char		*str;
  char		*arg;
  t_cmd		*cmd;
};

#endif		/* !ACTION_H_ */
