/*
** game.h for game in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Jun 26 15:12:11 2015 Antoine Plaskowski
** Last update Sun Jul  5 20:04:32 2015 Antoine Plaskowski
*/

#ifndef		GAME_H_
# define	GAME_H_

typedef	struct	s_team	t_team;
typedef	struct	s_game	t_game;

# include	<stddef.h>
# include	<pthread.h>
# include	"player.h"
# include	"map.h"
# include	"egg.h"
# include	"option.h"

# define	MUTEX	pthread_mutex_t
# define	FOOD_BY_TIME	126

struct		s_team
{
  size_t	connect_max;
  size_t	len_team;
  char		*team;
};

struct		s_game
{
  MUTEX		mutex;
  size_t	size_team;
  t_team	*team;
  t_player	*player;
  t_egg		*egg;
  t_map		map;
  t_option	option;
  t_time	s_time;
  t_time	food;
};

t_game		*init_game(t_game * const game, char **argv, int const argc);
void		delete_game(t_game * const game);

#endif		/* !GAME_H_ */
