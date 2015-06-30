/*
** client.h for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Apr  9 16:43:20 2015 zwertv_e
** Last update Tue Jun 30 17:16:56 2015 Antoine Plaskowski
*/

#ifndef		CLIENT_H_
# define	CLIENT_H_

typedef	struct	s_client	t_client;
typedef	struct	s_string	t_string;

# include	"accept_client.h"
# include	"cbuf.h"
# include	"node.h"
# include	"game.h"
# include	"player.h"

struct		s_string
{
  t_node	node;
  char		*str;
};

struct		s_client
{
  t_node	node;
  t_clientaddr	ca;
  t_cbuf	cbuf;
  t_string	*to_write;
  t_player	*player;
};

t_client	*add_client(t_client *list, t_clientaddr const * const ca);
t_client	*remove_client(t_client *list, t_client *to_rem);
bool		set_team(t_client * const list, t_game * const game, char *str);

#endif		/* !CLIENT_H_ */
