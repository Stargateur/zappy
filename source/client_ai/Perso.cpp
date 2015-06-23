/*
** Perso.cpp for Perso in /home/mathon_j/rendu/PSU_2014_zappy/source/client_ai
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Fri Jun 19 18:57:30 2015 Jérémy MATHON
** Last update Tue Jun 23 09:57:00 2015 Jérémy MATHON
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
  this->mouv.push_back("avance");
  this->cpt++;
}

void	Perso::droite()
{
  this->_time += 7;
  this->mouv.push_back("droite");
  this->cpt++;
}

void	Perso::gauche()
{
  this->_time += 7;
  this->mouv.push_back("gauche");
  this->cpt++;
}

void	Perso::voir()
{
  this->_time += 7;
  this->mouv.push_back("voir");
  this->cpt++;
}

void	Perso::inventaire()
{
  this->_time += 7;
  this->mouv.push_back("inventaire");
  this->cpt++;
}

void	Perso::prend(std::string const &obj)
{
  (void)obj;
  this->_time += 7;
  this->mouv.push_back("prend");
  this->cpt++;
}

void	Perso::pose(std::string const &obj)
{
  (void)obj;
  this->_time += 7;
  this->mouv.push_back("pose");
  this->cpt++;
}

void	Perso::expulse()
{
  this->_time += 7;
  this->mouv.push_back("expulse");
  this->cpt++;
}

void	Perso::broadcast(std::string const &txt)
{
  (void)txt;
  this->_time += 7;
  this->mouv.push_back("broadcast");
  this->cpt++;
}

void	Perso::incantation()
{
  if (this->_invent._nourriture > 2)
    {
      this->_time += 300;
      this->mouv.push_back("incantation");
      this->cpt++;
    }
  else
    std::cout << "I have not enough food to survive during the incantation..." << std::endl;
}

void	Perso::fork()
{
  this->_time += 42;
  this->mouv.push_back("fork");
  this->cpt++;
}

void	Perso::connect_nbr()
{

}

void	Perso::dead()
{
  std::cout << "I'm dead.." << std::endl;
}

void	Perso::main_loop()
{
  while (this->_invent._nourriture > 0)
    {
      if (this->_time % 126 == 0)
	{
	  this->_time = 0;
	  this->_invent._nourriture--;
	}
      /*
	TANT QUE (LIST.SIZE() <10 ) => Save action dans _action list
	IF (SIZE == 10) => WAIT Reponse server
	QUAND réponse server -> faire l'action via la fonction adéquate (ajout dans la Save directement dans la fonction avec incrémentation du cpt)
	RM le maillon de list
       */
      if (this->cpt >= 100)
	{
	  this->mouv.pop_front();
	}
    }
}
