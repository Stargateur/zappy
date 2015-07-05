/*
** egg.h for egg in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Jul  3 16:22:03 2015 Antoine Plaskowski
** Last update Sun Jul  5 05:48:03 2015 Antoine Plaskowski
*/

#ifndef		EGG_H_
# define	EGG_H_

typedef	struct	s_egg	t_egg;

# include	"node.h"
# include	"player.h"
# include	"time.h"
# include	"team.h"

struct		s_egg
{
  t_node	node;
  t_coord	coord;
  t_time	time;
  t_time	timeout;
  t_team	*team;
};

t_egg		*add_egg(t_egg *list, t_coord *coord, t_team *team, size_t t);
bool		egg(t_game *game, t_player *player, char *str);
bool		hatches_egg(t_game *game);

#endif		/* !EGG_H_ */
