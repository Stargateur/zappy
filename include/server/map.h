/*
** map.h for  in /home/zwertv_e/rendu/PSU_2014_zappy/include/server
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Jun 18 17:34:34 2015 zwertv_e
** Last update Wed Jul  1 14:44:46 2015 zwertv_e
*/

#ifndef		MAP_H__
# define	MAP_H__

# include	<stdbool.h>
# include	<stddef.h>

typedef	struct	s_map		t_map;
typedef	struct	s_square	t_square;
typedef	struct	s_coords	t_coords;

# define        DENSITY		(2.0)
# define	DENSITY_LIN	(1.0)
# define	DENSITY_DER	(1.0)
# define	DENSITY_SIB	(1.0)
# define	DENSITY_MEN	(1.0)
# define	DENSITY_PHI	(1.0)
# define	DENSITY_THY	(1.0)
# define	DENSITY_FOOD	(5.0)

# include	"inv.h"
# include	"node.h"

struct		s_coords
{
  size_t	x;
  size_t	y;
};

struct		s_map
{
  size_t	height;
  size_t	width;
  t_square	*items;
};

struct		s_square
{
  t_node	node;
  t_coords	coords;
  t_inv		ressources;
};

t_map		*init_map(t_map *map, size_t height, size_t width);
bool		map_generate(t_map * const map);
void		free_map(t_map *map);
bool		add_item(t_map *map, size_t const x, size_t const y,
			 int const type);
bool		delete_item(t_map *map, size_t const x, size_t const y,
			    int const type);
size_t		prev_x(t_map const * const map, size_t x);
size_t	        next_x(t_map const * const map, size_t x);
size_t		prev_y(t_map const * const map, size_t y);
size_t	        next_y(t_map const * const map, size_t y);
t_square	*find_square(t_square *square, size_t const x, size_t const y);

#endif		/* MAP_H__ */
