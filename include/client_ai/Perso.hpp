/*
** Perso.hpp for Perso in /home/mathon_j/rendu/PSU_2014_zappy/include/client_ai
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Fri Jun 19 18:53:31 2015 Jérémy MATHON
** Last update Fri Jun 19 19:30:30 2015 Jérémy MATHON
*/

#ifndef PERSO_HPP_
# define PERSO_HPP_

#include	<iostream>
#include	<string>
#include	"Invent.hpp"

class	Perso
{
  int		_time;
  Invent	_invent;
public:
  Perso();
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
};

#endif /* !PERSO_HPP_ */
