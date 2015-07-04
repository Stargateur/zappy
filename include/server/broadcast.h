/*
** broadcast.h for broadcast in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Jul  1 07:45:51 2015 Antoine Plaskowski
** Last update Sat Jul  4 22:59:37 2015 Antoine Plaskowski
*/

#ifndef		BROADCAST_H_
# define	BROADCAST_H_

# include	<stdint.h>
# include	<math.h>

# define	M_PI_8	(M_PI / 8)

typedef	struct	s_minmax	t_minmax;

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
    S_HERE
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
t_sound		sound(t_map *map, t_player *player_a, t_player *player_b);

#endif		/* !BROADCAST_H_ */
