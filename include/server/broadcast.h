/*
** broadcast.h for broadcast in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Jul  1 07:45:51 2015 Antoine Plaskowski
** Last update Wed Jul  1 08:12:56 2015 Antoine Plaskowski
*/

#ifndef		BROADCAST_H_
# define	BROADCAST_H_

# include	<stdint.h>

typedef	enum	e_sound
  {
    S_EAST = 1,
    S_NORTH_EAST = 2,
    S_NORTH = 3,
    S_NORTH_WEST = 4,
    S_WEST = 5,
    S_SOUTH_WEST = 6,
    S_SOUTH = 7,
    S_SOUTH_EAST = 8,
    S_NONE
  }		t_sound;

typedef	struct	s_vector	t_vector;

# include	"map.h"
# include	"player.h"

struct		s_vector
{
  intmax_t	x;
  intmax_t	y;
};

t_sound		broadcast(t_map *map, t_player *player_a, t_player *player_b);

#endif		/* !BROADCAST_H_ */
