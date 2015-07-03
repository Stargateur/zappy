/*
** manage_select.h for manage_select in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jun 18 22:35:21 2015 Antoine Plaskowski
** Last update Fri Jul  3 18:02:03 2015 Alaric
*/

#ifndef		MANAGE_SELECT_H_
# define	MANAGE_SELECT_H_

# include	<stdbool.h>
# include	"game.h"
# include	"client.h"

t_client	*manage_select(t_client *client, int const sfd);

#endif		/* !MANAGE_SELECT_H_ */
