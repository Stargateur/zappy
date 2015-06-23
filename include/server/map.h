/*
** map.h for  in /home/zwertv_e/rendu/PSU_2014_zappy/include/server
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Jun 18 17:34:34 2015 zwertv_e
** Last update Tue Jun 23 18:13:51 2015 zwertv_e
*/

#ifndef		MAP_H__
# define	MAP_H__

# include	<stdbool.h>
# include	"inv.h"
# include	"player.h"
# include	"node.h"

typedef	struct	s_map		t_map;
typedef	struct	s_squarre	t_squarre;

# define        DENSITY		(1)
# define	RARITY_LIN	(9)
# define	RARITY_DER	(8)
# define	RARITY_SIB	(10)
# define	RARITY_MEN	(5)
# define	RARITY_PHI	(6)
# define	RARITY_THY	(1)

struct		s_squarre
{
  t_node	node;
  size_t	x;
  size_t	y;
  t_inv		ressources;
};

struct		s_map
{
  size_t	height;
  size_t	width;
  t_squarre	*items;
};

void		init_map(t_map *map, size_t height, size_t width);
void		free_map(t_map *map);
bool		add_item(t_map *map, size_t const x, size_t const y,
			 int const type);
bool		delete_item(t_map *map, size_t const x, size_t const y,
			    int const type);

#endif		/* MAP_H__ */
