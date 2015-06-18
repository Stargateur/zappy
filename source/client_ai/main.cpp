//
// main.cpp for main in /home/alix/unix/new_year/zappy
// 
// Made by amoure_a
// Login   <alix amoureux@epitech.net>
// 
// Started on  Wed Jun  3 22:08:07 2015 amoure_a
// Last update Mon Jun 15 12:46:53 2015 amoure_a
//

#include		"Client.h"

int			get_port(std::string port)
{
  int		value;
  size_t	res;

  res = port.find_first_not_of("0123456789");
  if (res != (size_t)-1)
    {
      std::cerr << "The port is not correct" << std::endl;
      exit(-1);
    }
  value = atoi(port.c_str());
  return (value);
}

std::string		get_ip(std::string ip)
{
  size_t		res;

  res = ip.find_first_not_of("0123456789.");
  if (res != (size_t)-1)
    {
      std::cerr << "The ip is not correct" << std::endl;
      exit(-1);
    }
  return (ip);
}

void			connect_to_server(std::string team, int port, std::string ip)
{
  Client		client(team, port, ip);

  client.connect_client();
}

void			parse_arguments(int ac, char **av)
{
  int		i;
  std::string	value;
  std::string	team;
  int		port;
  std::string	ip;

  i = 1;
  while (i < ac)
    {
      value = av[i];
      if (value.compare("-n") == 0)
	team = av[++i];
      else if (value.compare("-p") == 0)
	port = get_port(av[++i]);
      else if (value.compare("-h") == 0)
	ip = get_ip(av[++i]);
      else
	std::cerr << "The option " << value << " does not exist" << std::endl;
      i++;
    }
  connect_to_server(team, port, ip);
}

int		main(int ac, char **av)
{
  if (ac == 7)
    {
      parse_arguments(ac, av);
    }
  else
    std::cerr << "Bad number of arguments : ./client -n name_team -p port -h ip" << std::endl;
  return (0);
}
