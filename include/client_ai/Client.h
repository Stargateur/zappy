/*
** Client.h for Client in /home/xila/unix/new_year/zappy
** 
** Made by amoure_a
** Login   <alix amoureux@epitech.net>
** 
** Started on  Mon Jun 15 12:15:16 2015 amoure_a
** Last update Sun Jul  5 03:46:40 2015 Antoine Plaskowski
*/

#ifndef		CLIENT_H_
# define	CLIENT_H_

# include	<iostream>
# include	<string.h>
# include	<cstdlib>
# include	<unistd.h>
# include	<netdb.h>
# include	<sys/types.h>
# include	<sys/socket.h>
# include	<arpa/inet.h>

class		Client
{
 private:
  std::string	ip;
  std::string	team_name;
  int		port;
  int		client;

 public:
  Client(std::string team, int port, std::string ip);
  ~Client();
  void		connect_client();
  int		init_client();
  void		do_client();
  int		getClient() const;
  std::string	getTeam() const;
};

#endif
