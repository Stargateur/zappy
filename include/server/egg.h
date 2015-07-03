/*
** egg.h for egg in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Jul  3 16:22:03 2015 Antoine Plaskowski
** Last update Fri Jul  3 16:30:55 2015 Antoine Plaskowski
*/

#ifndef		EGG_H_
# define	EGG_H_

# include	"node.h"
# include	"player.h"

typedef	struct	s_egg	t_egg;

struct		s_egg
{
  t_node	node;
  t_coord	coord;
};

#endif		/* !EGG_H_ */
