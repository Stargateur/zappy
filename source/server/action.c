/*
** action.c for action in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Jun 29 18:18:56 2015 Antoine Plaskowski
** Last update Tue Jun 30 19:53:04 2015 Antoine Plaskowski
*/

#include	"action.h"

bool		show_action(t_action *action)
{
  action = first_node(&action->node);
  while (action != NULL)
    {
      printf("%s\n", action->str);
      action = action->node.next;
    }
  return (false);
}
