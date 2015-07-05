/*
** player_levelup.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Wed Jul  1 17:51:47 2015 zwertv_e
** Last update Sun Jul  5 07:10:36 2015 Antoine Plaskowski
*/

#include	"map.h"
#include	"game.h"
#include	"inv.h"

static t_lvlup	g_needs[7] = {
  {1, {1, 0, 0, 0, 0, 0, 0}},
  {2, {1, 1, 1, 0, 0, 0, 0}},
  {2, {2, 0, 1, 0, 2, 0, 0}},
  {4, {1, 1, 2, 0, 1, 0, 0}},
  {4, {1, 2, 1, 3, 0, 0, 0}},
  {6, {1, 2, 3, 0, 1, 0, 0}},
  {6, {2, 2, 2, 2, 2, 1, 0}}
};

static size_t	g_s_needs = sizeof(g_needs) / sizeof(*g_needs);

static size_t	get_nb_players(t_game const * const game, size_t const range,
			       size_t const x, size_t const y)
{
  t_player	*tmp;
  size_t	res;

  res = 0;
  tmp = first_node(&game->player->node);
  while (tmp != NULL)
    {
      if (range != tmp->range)
	return (0);
      if (tmp->coord.x == x && tmp->coord.y == y)
	res++;
      tmp = tmp->node.next;
    }
  return (res);
}

static bool	can_levelup(t_square const * const square,
			    t_player const * const player,
			    size_t const nb_player)
{
   size_t	i;

  if (square == NULL || player == NULL)
    return (true);
  if ((i = player->range - 1) > NB_LEVEL)
    return (true);
  if (nb_player != g_needs[i].nb_players)
    return (true);
  if (square->ressources.linemate != g_needs[i].ressources.linemate)
    return (true);
  if (square->ressources.deraumere != g_needs[i].ressources.deraumere)
    return (true);
  if (square->ressources.sibur != g_needs[i].ressources.sibur)
    return (true);
  if (square->ressources.mendiane != g_needs[i].ressources.mendiane)
    return (true);
  if (square->ressources.phiras != g_needs[i].ressources.phiras)
    return (true);
  if (square->ressources.thystame != g_needs[i].ressources.thystame)
    return (true);
  return (false);
}

static bool	do_levelup(t_game * const game,
			   t_square * const sq,
			   size_t const i)
{
  t_player	*tmp;

  if (game == NULL || sq == NULL || i > NB_LEVEL ||
      add_ressource(&sq->ressources, LINEMATE,
		    g_needs[i].ressources.linemate, false) == true ||
      add_ressource(&sq->ressources, DERAUMERE,
		    g_needs[i].ressources.deraumere, false) == true ||
      add_ressource(&sq->ressources, SIBUR,
		    g_needs[i].ressources.sibur, false) == true ||
      add_ressource(&sq->ressources, MENDIANE,
		    g_needs[i].ressources.mendiane, false) == true ||
      add_ressource(&sq->ressources, PHIRAS,
		    g_needs[i].ressources.phiras, false) == true ||
      add_ressource(&sq->ressources, THYSTAME,
		    g_needs[i].ressources.thystame, false) == true)
    return (true);
  tmp = first_node(&game->player->node);
  while (tmp != NULL)
    {
      if (tmp->coord.x == sq->coord.x &&
	  tmp->coord.y == sq->coord.y && tmp->range == i + 1)
	tmp->range++;
      tmp = tmp->node.next;
    }
  return (false);
}

bool		player_levelup(t_game * const game,
			       t_map * const map, t_player * const player,
			       bool const do_)
{
  t_square	*square;
  size_t	nb_players;

  if (player->range - 1 >= g_s_needs)
    return (true);
  square = find_square(first_node(&map->items->node),
		       player->coord.x, player->coord.y);
  if (square == NULL)
    return (true);
  nb_players = get_nb_players(game, player->range,
			      player->coord.x, player->coord.y);
  if (nb_players == 0)
    return (true);
  if (can_levelup(square, player, nb_players) == true)
    return (true);
  if (do_ == true)
    return (do_levelup(game, square, player->range - 1));
  return (false);
}
