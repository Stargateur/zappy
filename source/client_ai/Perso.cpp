/*
** Perso.cpp for Perso in /home/mathon_j/rendu/PSU_2014_zappy/source/client_ai
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Fri Jun 19 18:57:30 2015 Jérémy MATHON
** Last update Fri Jun 19 19:13:59 2015 Jérémy MATHON
*/

#include	"Perso.hpp"

Perso::Perso() : _time(0)
{

}

Perso::~Perso()
{
}

void	Perso::avance()
{
  this->_time += 7;
}

void	Perso::droite()
{
 this->_time += 7;
}

void	Perso::gauche()
{
  this->_time += 7;
}

void	Perso::voir()
{
  this->_time += 7;
}

void	Perso::inventaire()
{
  this->_time += 7;
}

void	Perso::prend(std::string const &obj)
{
  this->_time += 7;
}

void	Perso::pose(std::string const &obj)
{
  this->_time += 7;
}

void	Perso::expulse()
{
  this->_time += 7;
}

void	Perso::broadcast(std::string const &txt)
{
  this->_time += 7;
}

void	Perso::incantation()
{
  if (this->_invent._nourriture > 2)
    {
      this->_time += 300;
    }
  else
    std::cout << "I have not enough food to survive during the incantation..." << std::endl;
}

void	Perso::fork()
{
  this->_time += 42;
}

void	Perso::connect_nbr()
{

}

void	Perso::dead()
{
  std::cout << "I'm dead.." << std::endl;
  ~Perso();
}
