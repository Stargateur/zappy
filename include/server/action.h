/*
** action.h for action in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Jun 29 18:18:24 2015 Antoine Plaskowski
** Last update Mon Jun 29 19:12:00 2015 Antoine Plaskowski
*/

#ifndef		ACTION_H_
# define	ACTION_H_

typedef	struct	s_action	t_action;

struct		s_action
{
  t_node	node;
  char		*str;
  char		*arg;
  void		*(*lol)(void);
};

#endif		/* !ACTION_H_ */
