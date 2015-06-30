/*
** inv.h for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 23 14:43:00 2015 zwertv_e
** Last update Tue Jun 30 17:18:50 2015 Antoine Plaskowski
*/

#ifndef		INV_H__
# define	INV_H__

typedef	struct	s_inv		t_inv;

# include	"node.h"

# define        RESC_COUNT	(7)

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

void		init_inv(t_inv *inv);
void		add_ressource(t_inv * const inv, int const type,
			      int const quantity);
size_t		count_ressources(t_inv const * const inv);
const char	*get_inventory(t_inv const * const inv);

#endif		/* INV_H__ */
