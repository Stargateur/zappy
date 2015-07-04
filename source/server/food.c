/*
** food.c for food in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Jul  4 11:34:29 2015 Antoine Plaskowski
** Last update Sun Jul  5 01:26:50 2015 Antoine Plaskowski
*/

#include	<stddef.h>
#include	"player.h"
#include	"food.h"

t_player	*food(t_player *player, t_time const *food, t_time act)
{
  if (player == NULL)
    return (NULL);
  if (time_sub(&act, &player->food) == true)
    return (delete_player(player));
  while (time_small(food, &act) == true)
    {
      if (player->inv.food == 0)
	return (delete_player(player));
      if (add_ressource(&player->inv, FOOD, 1, false) == true)
	return (delete_player(player));
      if (time_sub(&act, food) == true)
	return (delete_player(player));
      if (time_add(&player->food, food) == true)
	return (delete_player(player));
    }
  return (player);
}
