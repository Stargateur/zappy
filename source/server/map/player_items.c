/*
** player_items.c for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Wed Jul  1 15:12:00 2015 zwertv_e
** Last update Wed Jul  1 17:17:48 2015 zwertv_e
*/

#include	"map.h"
#include	"player.h"
#include	"inv.h"

bool		take_item(t_map * const map,
			  t_player * const player, int const type)
{
  if (!map || !player)
    return (false);
  if (!delete_item(map, player->coords.x, player->coords.y, type))
    return (false);
  if (!add_ressource(&player->inv, type, 1, true))
    return (false);
  return (true);
}

bool		drop_item(t_map * const map,
			  t_player * const player, int const type)
{
  if (!map || !player)
    return (false);
  if (!add_item(map, player->coords.x, player->coords.y, type))
    return (false);
  if (!add_ressource(&player->inv, type, 1, false))
    return (false);
  return (true);
}
