/*
** client.c for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Apr  9 16:43:00 2015 zwertv_e
** Last update Thu Jun 18 22:43:38 2015 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"client.h"
#include	"cbuf.h"

t_client	*add_client(t_client * const list, t_clientaddr const * const ca)
{
  t_client	*new;

  if (ca == NULL)
    return (list);
  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->ca = *ca;
  init_cbuf(&new->cbuf);
  return (put_node(&list->node, &new->node));
}
