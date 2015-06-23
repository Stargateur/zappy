/*
** inv.c for  in /home/zwertv_e/rendu/PSU_2014_zappy/source/server/map
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Tue Jun 23 14:36:45 2015 zwertv_e
** Last update Tue Jun 23 15:01:03 2015 zwertv_e
*/

#include	"inv.h"

void		init_inv(t_inv *inv)
{
  inv->linemlate = 0;
  inv->deraumere = 0;
  inv->sibur = 0;
  inv->mendiane = 0;
  inv->phiras = 0;
  inv->thystame = 0;
  inv->food = 0;
}

void	        add_ressource(t_inv * const inv, int const type,
			      int const quantity)
{
  switch(type)
    {
    case linemlate:
      inv->linemlate += quantity;
      break;
    case deraumere:
      inv->deraumere += quantity;
      break;
    case sibur:
      inv->sibur += quantity;
      break;
    case mendiane:
      inv->mendiane += quantity;
      break;
    case phiras:
      inv->phiras += quantity;
      break;
    case thystame:
      inv->thystame += quantity;
      break;
    case food:
      inv->food += quantity;
      break;
    };
}

size_t		count_ressources(t_inv const * const inv)
{
  size_t		res;

  res = 0;
  res += inv->linemlate;
  res += inv->deraumere;
  res += inv->sibur;
  res += inv->mendiane;
  res += inv->phiras;
  res += inv->thystame;
  res += inv->food;
  return (res);
}
