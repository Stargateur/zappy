/*
** game.h for game in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Jun 26 15:12:11 2015 Antoine Plaskowski
** Last update Mon Jun 29 19:26:41 2015 Antoine Plaskowski
*/

#ifndef		GAME_H_
# define	GAME_H_

# include	"utils.h"
# include	"player.h"

typedef	struct	s_game	t_game;
struct		s_game
{
  size_t	*connect_nbr;
  t_player	*player;
  t_time	time;
};

#endif		/* !GAME_H_ */
