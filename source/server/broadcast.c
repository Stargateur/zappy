/*
** broadcast.c for broadcast in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Jul  1 06:56:53 2015 Antoine Plaskowski
** Last update Sun Jul  5 14:54:48 2015 Antoine Plaskowski
*/

#include	<math.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<stdint.h>
#include	"broadcast.h"
#include	"message.h"
#include	"utils.h"

static t_minmax	g_minmax[] =
  {
    {0 - M_PI_8, 0 + M_PI_8, S_EAST},
    {M_PI_4 - M_PI_8, M_PI_4 + M_PI_8, S_NORTH_EAST},
    {M_PI_2 - M_PI_8, M_PI_2 + M_PI_8, S_NORTH},
    {M_PI_4 * 3 - M_PI_8, M_PI_4 * 3 + M_PI_8, S_NORTH_WEST},
    {-M_PI_4 * 3 - M_PI_8, -M_PI_4 * 3 + M_PI_8, S_SOUTH_WEST},
    {-M_PI_2 - M_PI_8, -M_PI_2 + M_PI_8, S_SOUTH},
    {-M_PI_4 - M_PI_8, -M_PI_4 + M_PI_8, S_SOUTH_EAST},
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

static void	short_vector(t_v2d *v, t_map *map)
{
  t_v2d		m;
  t_v2d		origin;

  m.x = (intmax_t)map->width;
  m.y = (intmax_t)map->height;
  origin = *v;
  diff_vector(v, origin.x + m.x, origin.y + m.y);
  diff_vector(v, origin.x + m.x, origin.y - m.y);
  diff_vector(v, origin.x + m.x, origin.y);
  diff_vector(v, origin.x - m.x, origin.y + m.y);
  diff_vector(v, origin.x - m.x, origin.y - m.y);
  diff_vector(v, origin.x - m.x, origin.y);
  diff_vector(v, origin.x, origin.y + m.y);
  diff_vector(v, origin.x, origin.y - m.y);
}

static t_sound	true_sound(t_sound s, t_dir dir)
{
  switch (dir)
    {
    case NORTH:
      return (s);
    case EAST:
      return (s + 2 > S_NORTH_EAST ? (s + 2) % S_NORTH_EAST : s + 2);
    case SOUTH:
      return (s + 4 > S_NORTH_EAST ? (s + 4) % S_NORTH_EAST : s + 4);
    case WEST:
      return (s + 6 > S_NORTH_EAST ? (s + 6) % S_NORTH_EAST : s + 6);
    }
  return (S_HERE);
}

static t_sound	get_sound(t_map *map, t_player *dest, t_player *origin)
{
  t_v2d		vector;
  double	angle;
  size_t	i;

  if (map == NULL || dest == NULL || origin == NULL)
    return (S_HERE);
  vector.x = (intmax_t)origin->coord.x - (intmax_t)dest->coord.x;
  vector.y = (intmax_t)origin->coord.y - (intmax_t)dest->coord.y;
  short_vector(&vector, map);
  if (vector.x == 0 && vector.y == 0)
    return (S_HERE);
  if (vector.x == 0)
    return (true_sound(vector.y < 0 ? S_SOUTH : S_NORTH, dest->dir));
  if (vector.y == 0)
    return (true_sound(vector.x < 0 ? S_WEST : S_EAST, dest->dir));
  angle = atan2(vector.y, vector.x);
  for (i = 0; i < g_s_minmax; i++)
    if (angle >= g_minmax[i].min && angle <= g_minmax[i].max)
      return (true_sound(g_minmax[i].sound, dest->dir));
  return (true_sound(S_WEST, dest->dir));
}

bool		broadcast(t_game *game, t_player *player, char *arg)
{
  t_player	*tmp;
  char		*str;
  t_sound	sound;

  if (game == NULL || player == NULL || arg == NULL)
    return (true);
  tmp = first_node(&game->player->node);
  while (tmp != NULL)
    {
      if (tmp != player && tmp->client != NULL)
	{
	  sound = get_sound(&game->map, tmp, player);
	  str = malloc_vsnprintf("message %d,%s\n", sound, arg);
	  add_string(tmp->client, str);
	  free(str);
	}
      tmp = tmp->node.next;
    }
  add_string(player->client, OK);
  return (false);
}
