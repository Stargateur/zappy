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
  bool				_see;

public:
  Perso(std::string team, int port, std::string ip);
  ~Perso();
  void		avance();
  void		droite();
  void		gauche();
  void		voir(std::string &answer);
  void		inventaire(std::string &answer);
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
  std::string	server_answer(const std::string &action);
  void		execute_commands(std::string &answer, bool *death, std::string &action);
  int		welcome();
  const void	*getTeamName();
  void		size_map_pos_ia(std::string& coords);
  void		get_numclient(std::string num_client);
  int		find_number(std::string &answer, const char &char_end);
  void		save_objects_in_map(const std::string& objects, const int &i);
  void		put_objects_in_case(const int& x, const int &y, const std::string &answer, const int&);
  int		*find_obj_in_map(const t_case &obj);
  void		go_to_obj(int *coords_obj);
  void		go_up(int *, t_way *);
  void		go_down(int *, t_way *);
  void		go_left(int *, t_way *);
  void		go_right(int *, t_way *);
  int		count_obj_by_case(const std::string &, const std::string);
  void		search_food();
  void		search_linemate();
};

#endif /* !PERSO_HPP_ */
