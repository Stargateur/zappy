/*
** client.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Apr  9 16:43:00 2015 zwertv_e
** Last update Tue Jun 30 19:17:36 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"client.h"
#include	"cbuf.h"
#include	"game.h"
#include	"opt.h"

t_string	*add_string(t_string * const list, char *str)
{
  t_string	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->str = strdup(str);
  return (put_node(&list->node, &new->node));
}

t_client	*add_client(t_client * const list,
			    t_clientaddr const * const ca)
{
  t_client	*new;

  if (ca == NULL)
    return (list);
  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->ca = *ca;
  new->to_write = add_string(NULL, "BIENVENUE\n");
  new->player = NULL;
  init_cbuf(&new->cbuf);
  return (put_node(&list->node, &new->node));
}

static bool	anwser_team(t_client * const client, size_t const num_client)
{
  char		*str;
  int           len;

  if (client == NULL || client->player == NULL)
    return (true);
  if ((len = snprintf(NULL, 0, "%lu\n", num_client)) < 0)
    return (true);
  if ((str = malloc(sizeof(*str) * ((size_t)len + 1))) == NULL)
    return (true);
  if (snprintf(str, (size_t)len + 1, "%lu\n", num_client) != len)
    return (true);
  client->to_write = add_string(client->to_write, str);
  free(str);
  if ((len = snprintf(NULL, 0, "%lu %lu\n", client->player->x, client->player->y)) < 0)
    return (true);
  if ((str = malloc(sizeof(*str) * ((size_t)len + 1))) == NULL)
    return (true);
  if (snprintf(str, (size_t)len + 1, "%lu %lu\n", client->player->x, client->player->y) != len)
    return (true);
  client->to_write = add_string(client->to_write, str);
  free(str);
  return (false);
}

bool		set_team(t_client * const client, t_game * const game,
			 char * str)
{
  t_player	*player;
  size_t	team;

  str = strtok(str, " ");
  if (client == NULL || game == NULL || str == NULL || game->team == NULL)
    return (true);
  for (team = 0; team < game->size_team; team++)
    if (strncmp(game->team[team].team, str, game->team[team].len_team) == 0)
      {
	if (game->team[team].connect < game->team[team].connect_max)
	  {
	    game->team[team].connect++;
	    if ((player = find_free_player(game->player, game->team[team].team)) == NULL)
	      player = init_player(malloc(sizeof(*player)), rand(), rand(), game->team[team].team);
	    if (player == NULL)
	      return (true);
	    client->player = player;
	    player->client = client;
	    return (anwser_team(client, game->team[team].connect_max - game->team[team].connect));
	  }
	else
	  return (true);
      }
  return (true);
}
