/*
** handler.h for handler in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jun 18 21:37:38 2015 Antoine Plaskowski
** Last update Fri Jun 19 15:45:19 2015 Antoine Plaskowski
*/

#ifndef		HANDLER_H_
# define	HANDLER_H_

# include	<stdbool.h>

extern bool	g_keep_running;

void		int_handler(int const signum);

#endif		/* !HANDLER_H_ */
