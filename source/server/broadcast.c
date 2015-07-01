/*
** broadcast.c for broadcast in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Jul  1 06:56:53 2015 Antoine Plaskowski
** Last update Wed Jul  1 09:24:49 2015 Antoine Plaskowski
*/

#include	<math.h>
#include	<stdint.h>
#include	"broadcast.h"

static void	diff_vector(t_vector *v1, intmax_t x, intmax_t y)
{
  if (sqrt(v1->x * v1->x + v1->y * v1->y) > sqrt(x * x + y * y))
    {
      v1->x = x;
      v1->y = y;
    }
}

static void	short_vector(t_vector *vector, size_t x_map, size_t y_map)
{
  t_vector	origin;

  origin = *vector;
  diff_vector(vector, origin.x + x_map, origin.y);
  diff_vector(vector, origin.x - x_map, origin.y);
  diff_vector(vector, origin.x, origin.y + y_map);
  diff_vector(vector, origin.x, origin.y - y_map);
}

static t_sound	same_sign(t_vector *vector)
{
  double	angle;

  if (vector->x == 0)
    return (vector->y < 0 ? S_SOUTH : S_NORTH);
  angle = atan2(vector->y, vector->x);
  if (-M_PI_2 - M_PI_8 < angle && angle < -M_PI_2 + M_PI_8)
    return (S_SOUTH);
  if (-M_PI_4 * 3 - M_PI_8 <= angle && angle <= -M_PI_4 * 3 + M_PI_8)
    return (S_SOUTH_WEST);
  if (-M_PI - M_PI_8 < angle && angle < -M_PI + M_PI_8)
    return (S_WEST);
  if (M_PI_2 - M_PI_8 < angle && angle < M_PI_2 + M_PI_8)
    return (S_NORTH);
  if (M_PI_4 - M_PI_8 <= angle && angle <= M_PI_4 + M_PI_8)
    return (S_NORTH_EAST);
  if (-M_PI - M_PI_8 < angle && angle < -M_PI + M_PI_8)
    return (S_EAST);
  return (S_HERE);
}

static t_sound	not_same_sign(t_vector *vector)
{
}

t_sound		broadcast(t_map *map, t_player *player_a, t_player *player_b)
{
  t_vector	vector;

  if (map == NULL || player_a == NULL || player_b == NULL)
    return (S_HERE);
  vector.x = player_b->x - player_a->x;
  vector.y = player_b->y - player_a->y;
  short_vector(&vector, map->width, map->height);
  if (vector.x == 0 && vector.y == 0)
    return (S_HERE);
  if ((vector.x < 0) == (vector.y < 0))
    return (same_sign(&vector));
  return (not_same_sign(&vector));
}
