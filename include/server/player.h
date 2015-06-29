/*
** player.h for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 23 14:52:23 2015 zwertv_e
** Last update Mon Jun 29 22:52:31 2015 Antoine Plaskowski
*/

#ifndef		PLAYER_H__
# define	PLAYER_H__

typedef	struct	s_player	t_player;

typedef	enum
  {
    NORTH,
    SOUTH,
    WEST,
    EAST
  }		t_dir;

# include	"utils.h"
# include	"inv.h"
# include	"node.h"
# include	"map.h"
# include	"action.h"

struct		s_player
{
  t_node	node;
  size_t	x;
  size_t	y;
  t_dir		dir;
  size_t	range;
  char		*team;
  t_inv		inv;
  t_time	time;
  t_action	*action;
};

void		init_player(t_player * const player, size_t const x,
			    size_t const y, char const * const team);
void		move(t_map const * const map, t_player * const player);
void		rotate_left(t_player * const player);
void		rotate_right(t_player * const player);

#endif		/* PLAYER_H__ */
