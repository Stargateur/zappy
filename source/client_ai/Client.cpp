//
// Client.cpp for Client in /home/xila/unix/new_year/zappy
// 
// Made by amoure_a
// Login   <alix amoureux@epitech.net>
// 
// Started on  Mon Jun 15 12:25:45 2015 amoure_a
// Last update Mon Jun 29 15:28:37 2015 amoure_a
//

#include		"Client.h"

Client::Client(std::string team, int port, std::string ip)
{
  this->team_name = team;
  this->port = port;
  this->ip = ip;
}

Client::~Client()
{
}

int			Client::init_client()
{
  struct protoent       *pe;
  struct sockaddr_in    addr;
  int                   c;

  if ((pe = getprotobyname("TCP")) == NULL)
    {
      std::cerr << "Error on getproto" << std::endl;
      return (-1);
    }
  if ((this->client = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    {
      std::cerr << "Error on socket" << std::endl;
      return (-1);
    }
  addr.sin_family = AF_INET;
  addr.sin_port = htons(this->port);
  addr.sin_addr.s_addr = inet_addr(this->ip.c_str());
  if ((c = connect(this->client, (const struct sockaddr *)&addr, sizeof(addr))) == -1)
    {
      std::cerr << "Error on connect" << std::endl;
      return (-1);
    }
  return (1);
}

int			Client::getClient() const
{
  return (this->client);
}

std::string		Client::getTeam() const
{
  return (this->team_name);
}
