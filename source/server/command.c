/*
** command.c for command in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Jul  1 04:53:28 2015 Antoine Plaskowski
** Last update Wed Jul  1 05:26:33 2015 Antoine Plaskowski
*/

#include	<stdbool.h>
#include	<stdlib.h>
#include	"game.h"
#include	"client.h"

bool		get_cmd(t_game *game, t_client *client)
{
  char		*str;

  client = first_node(&client->node);
  while (client != NULL)
    {
      if (ready_cbuf(&client->cbuf) == true)
	{
	  if ((str = read_cbuf(&client->cbuf)) == NULL)
	    return (true);
	  if (client->player == NULL)
	    {
	      if (set_team(client, game, str) == true)
		return (true);
	    }
	  else
	    {
	      if (add_action(client->player, str) == true)
		return (true);
	    }
	  free(str);
	}
      if (client->player != NULL)
	show_action(client->player->action);
      client = client->node.next;
    }
  return (false);
}
