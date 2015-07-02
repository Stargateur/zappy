/*
** client.h for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Apr  9 16:43:20 2015 zwertv_e
** Last update Thu Jul  2 17:09:37 2015 Antoine Plaskowski
*/

#ifndef		CLIENT_H_
# define	CLIENT_H_

typedef	struct	s_client	t_client;
typedef	struct	s_string	t_string;

# include	"accept_client.h"
# include	"circular_buffer.h"
# include	"node.h"
# include	"game.h"
# include	"utils.h"
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
  bool		to_kill;
  t_time	time;
};

t_string	*add_string(t_string * const list, char *str);
t_client	*add_client(t_client *list, int const sfd);
bool		write_pos_player(t_client * const client);
t_client	*sup_client(t_client *client);

#endif		/* !CLIENT_H_ */
