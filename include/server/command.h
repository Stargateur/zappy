/*
** command.h for command in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Jul  1 05:24:19 2015 Antoine Plaskowski
** Last update Thu Jul  2 17:46:44 2015 Antoine Plaskowski
*/

#ifndef		COMMAND_H_
# define	COMMAND_H_

# include	<stdbool.h>
# include	"game.h"
# include	"client.h"

bool		get_cmd(t_game *game, t_client *client);

#endif		/* !COMMAND_H_ */
