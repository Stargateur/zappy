/*
** inv.h for  in /home/zwertv_e/rendu/PSU_2014_zappy
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 23 14:43:00 2015 zwertv_e
** Last update Sun Jul  5 03:46:22 2015 Antoine Plaskowski
*/

#ifndef		INV_H_
# define	INV_H_

typedef	struct	s_inv		t_inv;
typedef	enum	e_t_inv
  {
    LINEMATE = 0,
    DERAUMERE = 1,
    SIBUR = 2,
    MENDIANE = 3,
    PHIRAS = 4,
    THYSTAME = 5,
    FOOD = 6,
    NONE
  }		t_t_inv;

# include	<stdbool.h>
# include	"node.h"

# define        RESC_COUNT	(7)

typedef	struct	s_str_type_inv t_str_type_inv;

struct		s_str_type_inv
{
  char		*str;
  t_t_inv	type;
  size_t	len;
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

t_t_inv		get_type_inv(char const * const str);
t_inv		*init_inv(t_inv *inv);
bool		add_ressource(t_inv * const inv, int const type,
			      size_t const quantity, bool add);
size_t		count_ressources(t_inv const * const inv);
char		*get_inventory(t_inv const * const inv);

#endif		/* INV_H_ */
