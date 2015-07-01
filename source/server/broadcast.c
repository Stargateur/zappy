/*
** broadcast.c for broadcast in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Jul  1 06:56:53 2015 Antoine Plaskowski
** Last update Wed Jul  1 13:44:38 2015 zwertv_e
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

t_sound		broadcast(t_map *map, t_player *player_a, t_player *player_b)
{
  t_vector	vector;

  if (map == NULL || player_a == NULL || player_b == NULL)
    return (S_NONE);
  vector.x = player_b->coords.x - player_a->coords.x;
  vector.y = player_b->coords.y - player_a->coords.y;
  short_vector(&vector, map->width, map->height);
}
