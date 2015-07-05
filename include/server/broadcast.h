/*
** broadcast.h for broadcast in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Jul  1 07:45:51 2015 Antoine Plaskowski
** Last update Sun Jul  5 03:59:35 2015 Antoine Plaskowski
*/

#ifndef		BROADCAST_H_
# define	BROADCAST_H_

# include	<stdint.h>
# include	<math.h>

# define	M_PI_8	(M_PI / 8)

typedef	struct	s_minmax	t_minmax;

typedef	enum	e_sound
  {
    S_HERE = 0,
    S_NORTH = 1,
    S_NORTH_WEST = 2,
    S_WEST = 3,
    S_SOUTH_WEST = 4,
    S_SOUTH = 5,
    S_SOUTH_EAST = 6,
    S_EAST = 7,
    S_NORTH_EAST = 8
  }		t_sound;

typedef	struct	s_v2d	t_v2d;

# include	"map.h"
# include	"player.h"

struct		s_v2d
{
  intmax_t	x;
  intmax_t	y;
};

struct		s_minmax
{
  double	min;
  double	max;
  t_sound	sound;
};

bool		broadcast(t_game *game, t_player *player, char *str);

#endif		/* !BROADCAST_H_ */
