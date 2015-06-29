/*
** game.h for game in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Jun 26 15:12:11 2015 Antoine Plaskowski
** Last update Mon Jun 29 15:37:50 2015 Antoine Plaskowski
*/

#ifndef		GAME_H_
# define	GAME_H_

# include	<time.h>

typedef	struct	timespec	t_time;
typedef	struct	s_game	t_game;
struct		s_game
{
  size_t	*connect_nbr;
  t_time	time;
};



#endif		/* !GAME_H_ */
