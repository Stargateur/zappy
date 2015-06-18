/*
** init_fill_struct.c for init_fill_struct in /home/alix/unix/new_year/myftp/PSU_2014_myftp/src_server
** 
** Made by amoure_a
** Login   <alix amoureux@epitech.net>
** 
** Started on  Mon Mar 16 23:19:15 2015 amoure_a
// Last update Thu Jun 18 14:50:31 2015 amoure_a
*/

#include		"infos.h"

t_infos			*fill_struct()
{
  t_infos		*infos;
  char			*path1;
  char			*path2;
  char			*path3;

  return (infos);
}

int			init(int port)
{
  int			s;
  struct protoent	*pe;
  int			b;
  int			l;
  struct sockaddr_in	addr;

  if ((pe = getprotobyname("TCP")) == NULL)
    std::cerr << "Error on getproto" << std::endl;
  if ((s = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    std::cerr << "Error on socket" << std::endl;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;
  if ((b = bind((s), (const struct sockaddr *)&addr, sizeof(addr))) == -1)
    std::cerr << "Error on getproto" << std::endl;
  if ((l = listen((s), 42)) == -1)
    std::cerr << "Error on getproto" << std::endl;
  return (s);
}

int			add_socket(int port)
{
  int			s;
  struct protoent	*pe;
  int                   b;
  int                   l;
  struct sockaddr_in    addr;

  if ((pe = getprotobyname("TCP")) == NULL)
    std::cerr << "Error on getproto" << std::endl;
  if ((s = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    std::cerr << "Error on getproto" << std::endl;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = INADDR_ANY;
  if ((b = bind((s), (const struct sockaddr *)&addr, sizeof(addr))) == -1)
    std::cerr << "Error on getproto" << std::endl;
  if ((l = listen((s), 42)) == -1)
    std::cerr << "Error on getproto" << std::endl;
  return (s);
}
