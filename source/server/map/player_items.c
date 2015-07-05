/*
** player_items.c for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Wed Jul  1 15:12:00 2015 zwertv_e
** Last update Sun Jul  5 02:05:54 2015 Antoine Plaskowski
*/

#include	"map.h"
#include	"player.h"
#include	"inv.h"

bool		take_item(t_map * const map,
			  t_player * const player, int const type)
{
  if (map == NULL || player == NULL)
    return (true);
  if (delete_item(map, player->coord.x, player->coord.y, type) == true)
    return (true);
  if (add_ressource(&player->inv, type, 1, true) == true)
    return (true);
  return (false);
}

bool		drop_item(t_map * const map,
			  t_player * const player, int const type)
{
  if (map == NULL || player == NULL)
    return (true);
  if (add_item(map, player->coord.x, player->coord.y, type) == true)
    return (true);
  if (add_ressource(&player->inv, type, 1, false) == true)
    return (true);
  return (false);
}
