/*
** player.h for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 23 14:52:23 2015 zwertv_e
** Last update Tue Jun 23 14:58:43 2015 zwertv_e
*/

#ifndef		PLAYER_H__
# define	PLAYER_H__

# include	"inv.h"
# include	"node.h"

typedef	struct	s_player	t_player;

struct		s_player
{
  t_node	node;
  size_t	x;
  size_t	y;
  char		*team;
  t_inv		inv;
};

void		init_player(t_player *player, size_t const x,
			    size_t const y, char const * const team);

#endif		/* PLAYER_H__ */
