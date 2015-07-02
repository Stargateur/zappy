/*
** command.c for command in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Jul  1 04:53:28 2015 Antoine Plaskowski
** Last update Thu Jul  2 14:42:56 2015 Antoine Plaskowski
*/

#include	<stdbool.h>
#include	<stdlib.h>
#include	"game.h"
#include	"client.h"
#include	"team.h"
#include	"command.h"

static t_client	*aux_get_cmd(t_game *game, t_client *client, char *str)
{
  if (client->player == NULL)
    {
      if (set_team(client, game, str) == true)
	return (sup_client(client));
    }
  else
    {
      if (add_action(client->player, str) == true)
	return (client);
    }
  return (client);
}

t_client	*get_cmd(t_game *game, t_client *list)
{
  t_client	*client;
  t_client	*client2;
  char		*str;

  client = first_node(&list->node);
  while (client != NULL)
    {
      client2 = client->node.next;
      if (ready_cbuf(&client->cbuf) == true)
	{
	  if ((str = read_cbuf(&client->cbuf)) == NULL)
	    list = sup_client(client);
	  else
	    list = aux_get_cmd(game, client, str);
	  free(str);
	}
      client = client2;
    }
  return (list);
}
