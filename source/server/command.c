/*
** command.c for command in /home/plasko_a/projet/epitech/PSU_2014_zappy/source/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Jul  1 04:53:28 2015 Antoine Plaskowski
** Last update Thu Jul  2 18:07:11 2015 Antoine Plaskowski
*/

#include	<stdbool.h>
#include	<stdlib.h>
#include	"game.h"
#include	"client.h"
#include	"team.h"
#include	"command.h"
#include	"error_message.h"

static bool	aux_get_cmd(t_game *game, t_client *client, char *str)
{
  if (client->player == NULL)
    {
      if (set_team(client, game, str) == true)
	{
	  client->to_write = add_string(client->to_write, E_TEAM_1);
	  return (true);
	}
    }
  else
    {
      if (add_action(client->player, str) == true)
	return (false);
    }
  return (false);
}

bool		get_cmd(t_game *game, t_client *client)
{
  char		*str;

  client = first_node(&client->node);
  while (client != NULL)
    {
      if (ready_cbuf(&client->cbuf) == true)
	{
	  if ((str = read_cbuf(&client->cbuf)) == NULL)
	    client->to_kill = true;
	  else
	    if (aux_get_cmd(game, client, str) == true)
	      client->to_kill = true;
	  free(str);
	}
      client = client->node.next;
    }
  return (false);
}
