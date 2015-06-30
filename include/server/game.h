/*
** game.h for game in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Jun 26 15:12:11 2015 Antoine Plaskowski
** Last update Tue Jun 30 17:08:55 2015 Antoine Plaskowski
*/

#ifndef		GAME_H_
# define	GAME_H_

# include	<stddef.h>
# include	"player.h"

typedef	struct	s_team	t_team;
struct		s_team
{
  size_t	connect_nbr;
  char		*team;
};
typedef	struct	s_game	t_game;
struct		s_game
{
  size_t	size_team;
  t_team	*team;
  t_player	*player;
};

t_game		*init_game(t_game * const game);

#endif		/* !GAME_H_ */
