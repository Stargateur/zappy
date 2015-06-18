/*
** map.h for  in /home/zwertv_e/rendu/PSU_2014_zappy/include/server
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Jun 18 17:34:34 2015 zwertv_e
** Last update Thu Jun 18 23:40:55 2015 zwertv_e
*/

#ifndef		MAP_H__
# define	MAP_H__

# include	<stdbool.h>
# include	"node.h"

typedef	struct	s_map		t_map;
typedef	struct	s_squarre	t_squarre;
typedef	struct	s_player	t_player;
typedef	struct	s_inv		t_inv;

enum
  {
    linemlate,
    deraumere,
    sibur,
    mendiane,
    phiras,
    thystame,
    food
  };

struct		s_inv
{
  size_t	linemlate;
  size_t	deraumere;
  size_t	sibur;
  size_t	mendiane;
  size_t	phiras;
  size_t	thystame;
  size_t	food;
};

struct		s_squarre
{
  t_node	node;
  size_t	x;
  size_t	y;
  t_inv		ressources;
};

struct		s_player
{
  t_node	node;
  size_t	x;
  size_t	y;
  char		*team;
  t_inv		inv;
};

struct		s_map
{
  size_t	height;
  size_t	width;
  t_squarre	*items;
};

#endif		/* MAP_H__ */
