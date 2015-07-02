/*
** action.c for action in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Jun 29 18:18:56 2015 Antoine Plaskowski
** Last update Thu Jul  2 18:27:46 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	"action.h"

bool		show_action(t_action *action)
{
  printf("Les actions sont :\n");
  action = first_node(&action->node);
  while (action != NULL)
    {
      printf("%s\n", action->str);
      action = action->node.next;
    }
  return (false);
}
