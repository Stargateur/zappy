/*
** broadcast.c for broadcast in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Jul  1 06:56:53 2015 Antoine Plaskowski
** Last update Sat Jul  4 19:07:37 2015 Antoine Plaskowski
*/

#include	<math.h>
#include	<stdint.h>
#include	"broadcast.h"

static t_minmax	g_minmax[] =
  {
    {0 - M_PI_8, 0 + M_PI_8, S_EAST},
    {M_PI_4 - M_PI_8, M_PI_4 + M_PI_8, S_NORTH_EAST},
    {M_PI_2 - M_PI_8, M_PI_2 + M_PI_8, S_NORTH},
    {M_PI_4 * 3 - M_PI_8, M_PI_4 * 3 + M_PI_8, S_NORTH_WEST},
    {M_PI - M_PI_8, M_PI + M_PI_8, S_WEST},
    {M_PI_4 * 5 - M_PI_8, M_PI_4 * 5 + M_PI_8, S_SOUTH_WEST},
    {M_PI_2 * 3 - M_PI_8, M_PI_2 * 3 + M_PI_8, S_SOUTH},
    {M_PI_4 * 7 - M_PI_8, M_PI_4 * 7 + M_PI_8, S_SOUTH_EAST},
  };

static size_t	g_s_minmax = sizeof(g_minmax) / sizeof(*g_minmax);

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

  m.x = (intmax_t)map->width;
  m.y = (intmax_t)map->height;
  v->x = (intmax_t)b->x - (intmax_t)a->x;
  v->y = (intmax_t)b->y - (intmax_t)a->y;
  diff_vector(v, (intmax_t)a->x + m.x, (intmax_t)b->y + m.y);
  diff_vector(v, (intmax_t)a->x + m.x, (intmax_t)b->y - m.y);
  diff_vector(v, (intmax_t)a->x + m.x, (intmax_t)b->y);
  diff_vector(v, (intmax_t)a->x - m.x, (intmax_t)b->y + m.y);
  diff_vector(v, (intmax_t)a->x - m.x, (intmax_t)b->y - m.y);
  diff_vector(v, (intmax_t)a->x - m.x, (intmax_t)b->y);
  diff_vector(v, (intmax_t)a->x, (intmax_t)b->y + m.y);
  diff_vector(v, (intmax_t)a->x, (intmax_t)b->y - m.y);
}

static t_sound	minmax(t_v2d *vector)
{
  double	angle;
  size_t	i;

  angle = atan2(vector->y, vector->x);
  for (i = 0; i < g_s_minmax; i++)
    if (angle >= g_minmax[i].min && angle <= g_minmax[i].max)
      return (g_minmax[i].sound);
  return (S_HERE);
}

t_sound		broadcast(t_map *map, t_player *a, t_player *b)
{
  t_v2d		vector;

  if (map == NULL || a == NULL || b == NULL)
    return (S_HERE);
  short_vector(&a->coord, &b->coord, &vector, map);
  if (vector.x == 0 && vector.y == 0)
    return (S_HERE);
  if (vector.x == 0)
    return (vector.y < 0 ? S_SOUTH : S_NORTH);
  if (vector.y == 0)
    return (vector.x < 0 ? S_WEST : S_EAST);
  return (minmax(&vector));
}
