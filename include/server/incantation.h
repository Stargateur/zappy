/*
** incantation.h for incantation in /home/plasko_a/projet/epitech/PSU_2014_zappy/include/server
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Jul  4 22:48:39 2015 Antoine Plaskowski
** Last update Sun Jul  5 17:52:24 2015 Antoine Plaskowski
*/

#ifndef		INCANTATION_H_
# define	INCANTATION_H_

#include	"game.h"
#include	"player.h"

bool		incantation_en_cours(t_player *player);
bool		incantation(t_game *game, t_player *player, char *str);

#endif		/* !INCANTATION_H_ */
