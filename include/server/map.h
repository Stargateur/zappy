/*
** map.h for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Fri Jul  3 16:12:07 2015 zwertv_e
** Last update Sun Jul  5 05:20:04 2015 Antoine Plaskowski
*/

#ifndef		MAP_H_
# define	MAP_H_

# include	<stdbool.h>
# include	<stddef.h>

typedef	struct	s_map		t_map;
typedef	struct	s_square	t_square;
typedef	struct	s_coord		t_coord;

# define        DENSITY		(2.0)
# define	DENSITY_LIN	(1.0)
# define	DENSITY_DER	(1.0)
# define	DENSITY_SIB	(1.0)
# define	DENSITY_MEN	(1.0)
# define	DENSITY_PHI	(1.0)
# define	DENSITY_THY	(1.0)
# define	DENSITY_FOOD	(10.0)

# include	"inv.h"
# include	"node.h"

struct		s_coord
{
  size_t	x;
  size_t	y;
};

struct		s_map
{
  size_t	height;
  size_t	width;
  size_t	nbr_item;
  t_square	*items;
};

struct		s_square
{
  t_node	node;
  t_coord	coord;
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

#endif		/* MAP_H_ */
