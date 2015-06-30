/*
** client.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Apr  9 16:43:00 2015 zwertv_e
** Last update Tue Jun 30 17:10:07 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"client.h"
#include	"cbuf.h"
#include	"game.h"
#include	"opt.h"

t_string	*add_string(t_string * const list, char *str)
{
  t_string	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->str = str;
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

bool		set_team(t_client * const client, t_game * const game, char *str)
{
  size_t	team;

  if (client == NULL || game == NULL || str == NULL || game->team == NULL)
    return (true);
  for (team = 0; team < game->size_team; team++)
    if (strcmp(game->team[team].team, str) == 0)
      {
	
      }
  return (true);
}
