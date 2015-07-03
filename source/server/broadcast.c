/*
** broadcast.c for broadcast in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Jul  1 06:56:53 2015 Antoine Plaskowski
** Last update Fri Jul  3 15:38:36 2015 Antoine Plaskowski
*/

#include	<math.h>
#include	<stdint.h>
#include	"broadcast.h"

static void	diff_vector(t_v2d *v1, intmax_t x, intmax_t y)
{
  if (sqrt(v1->x * v1->x + v1->y * v1->y) > sqrt(x * x + y * y))
    {
      v1->x = x;
      v1->y = y;
    }
}

static void	short_vector(t_coord *a, t_coord *b, t_v2d *v, t_map *map)
{
  t_v2d		m;

  m.x = map->width;
  m.y = map->height;
  v->x = b->x - a->x;
  v->y = b->y - a->y;
  diff_vector(v, a->x + m.x, b->y + m.y);
  diff_vector(v, a->x + m.x, b->y - m.y);
  diff_vector(v, a->x + m.x, b->y);
  diff_vector(v, a->x - m.x, b->y + m.y);
  diff_vector(v, a->x - m.x, b->y - m.y);
  diff_vector(v, a->x - m.x, b->y);
  diff_vector(v, a->x, b->y + m.y);
  diff_vector(v, a->x, b->y - m.y);
}

static t_sound	same_sign(t_v2d *vector)
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
  if (M_PI - M_PI_8 < angle && angle < -M_PI + M_PI_8)
    return (S_EAST);
  return (S_HERE);
}

static t_sound	not_same_sign(t_v2d *vector)
{
}

t_sound		broadcast(t_map *map, t_player *a, t_player *b)
{
  t_v2d		vector;

  if (map == NULL || a == NULL || b == NULL)
    return (S_HERE);
  short_vector(&a->coord, &b->coord, &vector, map);
  if (vector.x == 0 && vector.y == 0)
    return (S_HERE);
  if ((vector.x < 0) == (vector.y < 0))
    return (same_sign(&vector));
  return (not_same_sign(&vector));
}
