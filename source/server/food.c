/*
** food.c for food in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Jul  4 11:34:29 2015 Antoine Plaskowski
** Last update Sat Jul  4 11:37:08 2015 Antoine Plaskowski
*/

#include	<stddef.h>
#include	"player.h"

t_player	*food(t_player *player, size_t const t)
{
  player = first_node(&player->node);
  while (player != NULL)
    {
      
      player = player->node.next;
    }
}
