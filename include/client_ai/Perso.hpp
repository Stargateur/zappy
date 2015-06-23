/*
** Perso.hpp for Perso in /home/mathon_j/rendu/PSU_2014_zappy/include/client_ai
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Fri Jun 19 18:53:31 2015 Jérémy MATHON
// Last update Tue Jun 23 14:06:47 2015 amoure_a
*/

#ifndef PERSO_HPP_
# define PERSO_HPP_

# include	<iostream>
# include	<string>
# include	<list>
# include	"Invent.hpp"
# include	"Save.h"
# include	"Client.h"

class	Perso : public Client
{
private:
  Save				*_sav;
  int				_time;
  Invent			_invent;
  std::list<std::string>	_action;
public:
  Perso(std::string team, int port, std::string ip);
  ~Perso();
  void	avance();
  void	droite();
  void	gauche();
  void	voir();
  void	inventaire();
  void	prend(std::string const &);
  void	pose(std::string const &);
  void	expulse();
  void	broadcast(std::string const &);
  void	incantation();
  void	fork();
  void	connect_nbr();
  void	dead();
  void	main_loop();
  std::string	do_action();
};

#endif /* !PERSO_HPP_ */
