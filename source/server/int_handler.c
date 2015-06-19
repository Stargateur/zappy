/*
** int_handler.c for int_handler in /home/plasko_a/projet/epitech/PSU_2014_zappy/include/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Jun 19 15:37:57 2015 Antoine Plaskowski
** Last update Fri Jun 19 15:46:31 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<signal.h>
#include	"int_handler.h"

bool		g_keep_running = true;

void		int_handler(int const signum)
{
  if (signal(SIGINT, int_handler) == SIG_ERR)
    perror("signal()");
  (void)signum;
  g_keep_running = false;
}

