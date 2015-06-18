/*
** client.h for  in /home/zwertv_e/rendu/PSU_2014_myirc
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Apr  9 16:43:20 2015 zwertv_e
** Last update Thu Jun 18 18:47:06 2015 Antoine Plaskowski
*/

#ifndef		CLIENT_H_
# define	CLIENT_H_

# include	"node.h"

typedef	struct	s_client	t_client;

struct		s_client
{
  t_node	node;
  int		fd;
};

t_client	*add_client(t_client *list, int const _client);
t_client	*remove_client(t_client *list, t_client *to_rem);
t_client	*remove_client_at(t_client *list, int const pos);
t_client	*remove_client_if(t_client *list, int (*fnc)(t_client *));
t_client	*find_client(t_client *list, int fd);
t_client	*clean_client(t_client *clients);

#endif		/* !CLIENT_H_ */
