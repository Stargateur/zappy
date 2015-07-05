//
// main.cpp for main in /home/alix/unix/new_year/zappy
//
// Made by amoure_a
// Login   <alix amoureux@epitech.net>
//
// Started on  Wed Jun  3 22:08:07 2015 amoure_a
// Last update Tue Jun 30 15:25:31 2015 amoure_a
//

#include		"Perso.hpp"

int			get_port(std::string port)
{
  int		value;
  size_t	res;

  res = port.find_first_not_of("0123456789");
  if (res != (size_t)-1)
    {
      std::cerr << "The port is not correct" << std::endl;
      return (-1);
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
      return ("KO");
    }
  return (ip);
}

void			connect_to_server(std::string team, int port, std::string ip)
{
  Perso			perso(team, port, ip);

  if (perso.init_client() != -1)
    {
      if (perso.welcome() != -1)
	{
	  perso.main_loop();
	  close(perso.getClient());
	}
    }
}

void			parse_arguments(int ac, char **av)
{
  int		i;
  std::string	value;
  std::string	team;
  int		port = 4242;
  std::string	ip("localhost");

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
  if (port != -1 && ip.compare("KO") != 0)
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
