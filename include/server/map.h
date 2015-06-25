/*
** map.h for  in /home/zwertv_e/rendu/PSU_2014_zappy/include/server
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Jun 18 17:34:34 2015 zwertv_e
** Last update Thu Jun 25 22:52:23 2015 zwertv_e
*/

#ifndef		MAP_H__
# define	MAP_H__

typedef	struct	s_map		t_map;
typedef	struct	s_squarre	t_squarre;

# define        DENSITY		(2.0)
# define	DENSITY_LIN	(1.0)
# define	DENSITY_DER	(1.0)
# define	DENSITY_SIB	(1.0)
# define	DENSITY_MEN	(1.0)
# define	DENSITY_PHI	(1.0)
# define	DENSITY_THY	(1.0)
# define	DENSITY_FOOD	(5.0)

# include	<stdbool.h>
# include	"inv.h"
# include	"player.h"
# include	"node.h"

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
