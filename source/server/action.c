/*
** action.c for action in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Jun 29 18:18:56 2015 Antoine Plaskowski
** Last update Sun Jul  5 17:54:53 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"player.h"
#include	"utils.h"
#include	"action.h"
#include	"message.h"
#include	"food.h"
#include	"incantation.h"

bool		show_action(t_action *action)
{
  printf("Les actions sont :\n");
  action = first_node(&action->node);
  while (action != NULL)
    {
      printf("%s\n", action->str);
      action = action->node.next;
    }
  return (false);
}

static void	exec_action(t_game *game, t_player *player, t_action *action)
{
  if (action->arg == NULL || action->cmd == NULL)
    {
      add_string(player->client, KO);
      return;
    }
  if (action->cmd->fct(game, player, action->arg) == true)
    {
      add_string(player->client, KO);
      return;
    }
}

static bool	aux(t_game *game, t_player *player, t_time act, bool ret)
{
  t_time	cpy_action;

  player->action = first_node(&player->action->node);
  if (player->action == NULL)
    return (true);
  if (time_sub(&act, &player->act) == true)
    return (true);
  while (time_small(&player->action->time, &act) == true)
    {
      exec_action(game, player, player->action);
      time_add(&player->act, &player->action->time);
      time_sub(&act, &player->action->time);
      player->action = delete_action(player->action);
      if (player->action == NULL)
	return (true);
      incantation_en_cours(player);
    }
  cpy_action = player->action->time;
  time_sub(&cpy_action, &act);
  if (ret == true || time_small(&cpy_action, &game->s_time) == true)
    {
      game->s_time = cpy_action;
      return (false);
    }
  return (true);
}

bool		do_action(t_game *game)
{
  t_player	*player;
  t_player	*player2;
  t_time	actual_time;
  bool		ret;

  if (game == NULL)
    return (true);
  ret = true;
  if (clock_gettime(CLOCK_MONOTONIC_RAW, &actual_time) == -1)
    {
      perror("clock_gettime :");
      return (true);
    }
  player = first_node(&game->player->node);
  while (player != NULL)
    {
      player2 = player->node.next;
      game->player = food(player, &game->food, actual_time);
      if (game->player == player)
	if (aux(game, player, actual_time, ret) == false)
	  ret = false;
      player = player2;
    }
  return (ret);
}

t_action	*delete_action(t_action *action)
{
  if (action == NULL)
    return (NULL);
  free(action->str);
  return (sup_node(&action->node));
}
