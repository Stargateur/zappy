/*
** Perso.hpp for Perso in /home/mathon_j/rendu/PSU_2014_zappy/include/client_ai
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Fri Jun 19 18:53:31 2015 Jérémy MATHON
// Last update Fri Jul  3 15:49:53 2015 amoure_a
*/

#ifndef PERSO_HPP_
# define PERSO_HPP_

# include	<iostream>
# include	<string>
# include	<list>
# include	<algorithm>
# include	"Invent.hpp"
# include	"Save.h"
# include	"Client.h"

typedef	enum	s_way
  {
    RIGHT = 0,
    DOWN = 1,
    LEFT = 2,
    UP = 3
  }		t_way;

class	Perso : public Client
{
private:
  Save				*_sav;
  int				_time;
  Invent			_invent;
  std::list<std::string>	_action;
  int				_posx;
  int				_posy;
  t_way				_way;
  int				_mapheight;
  int				_maplength;
  int				_numclient;
  int				_nbunusedslots;
  int				_level;

public:
  Perso(std::string team, int port, std::string ip);
  ~Perso();
  void		avance();
  void		droite();
  void		gauche();
  void		voir(std::string answer);
  void		inventaire(std::string answer);
  void		prend(std::string const &);
  void		pose(std::string const &);
  void		expulse();
  void		broadcast(std::string const &);
  void		incantation();
  void		fork();
  void		connect_nbr();
  void		dead();
  void		main_loop();
  void		find_actions();
  std::string	server_answer(std::string action);
  void		execute_commands(std::string &answer, bool *death, std::string action);
  void		welcome();
  const void	*getTeamName();
  void		size_map_pos_ia(std::string coords);
  void		get_numclient(std::string num_client);
  int		find_number(std::string &answer, char char_end);
  void		save_objects_in_map(std::string objects, int i);
  void		see_map();
  void		put_objects_in_case(int x, int y, std::string answer);
  int		*find_obj_in_map(t_case obj);
  void		go_to_obj(int *coords_obj);
  void		go_up(int *, int *);
  void		go_down(int *, int *);
  void		go_left(int *, int *);
  void		go_right(int *, int *);
};

#endif /* !PERSO_HPP_ */
