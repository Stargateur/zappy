/*
** inv.h for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 23 14:43:00 2015 zwertv_e
** Last update Thu Jul  2 15:23:39 2015 zwertv_e
*/

#ifndef		INV_H__
# define	INV_H__

typedef	struct	s_inv		t_inv;

# include	<stdbool.h>
# include	"node.h"

# define        RESC_COUNT	(7)

enum
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    FOOD
  };

struct		s_inv
{
  size_t	linemate;
  size_t	deraumere;
  size_t	sibur;
  size_t	mendiane;
  size_t	phiras;
  size_t	thystame;
  size_t	food;
};

void		init_inv(t_inv *inv);
bool		add_ressource(t_inv * const inv, int const type,
			      size_t const quantity, bool add);
size_t		count_ressources(t_inv const * const inv);
const char	*get_inventory(t_inv const * const inv);

#endif		/* INV_H__ */
