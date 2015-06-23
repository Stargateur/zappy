/*
** Perso.cpp for Perso in /home/mathon_j/rendu/PSU_2014_zappy/source/client_ai
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Fri Jun 19 18:57:30 2015 Jérémy MATHON
// Last update Tue Jun 23 15:12:10 2015 amoure_a
*/

#include	"Perso.hpp"

Perso::Perso(std::string team, int port, std::string ip) : Client(team, port, ip)
{
  this->_sav = new Save();
  this->_time = 1260;
}

Perso::~Perso()
{
}

void	Perso::avance()
{
  this->_time += 7;
  this->_sav->mouv.push_back("avance");
  this->_sav->cpt++;
}

void	Perso::droite()
{
  this->_time += 7;
  this->_sav->mouv.push_back("droite");
  this->_sav->cpt++;
}

void	Perso::gauche()
{
  this->_time += 7;
  this->_sav->mouv.push_back("gauche");
  this->_sav->cpt++;
}

void	Perso::voir()
{
  this->_time += 7;
  this->_sav->mouv.push_back("voir");
  this->_sav->cpt++;
}

void	Perso::inventaire()
{
  this->_time += 7;
  this->_sav->mouv.push_back("inventaire");
  this->_sav->cpt++;
}

void	Perso::prend(std::string const &obj)
{
  (void)obj;
  this->_time += 7;
  this->_sav->mouv.push_back("prend");
  this->_sav->cpt++;
}

void	Perso::pose(std::string const &obj)
{
  (void)obj;
  this->_time += 7;
  this->_sav->mouv.push_back("pose");
  this->_sav->cpt++;
}

void	Perso::expulse()
{
  this->_time += 7;
  this->_sav->mouv.push_back("expulse");
  this->_sav->cpt++;
}

void	Perso::broadcast(std::string const &txt)
{
  (void)txt;
  this->_time += 7;
  this->_sav->mouv.push_back("broadcast");
  this->_sav->cpt++;
}

void	Perso::incantation()
{
  if (this->_invent._nourriture > 2)
    {
      this->_time += 300;
      this->_sav->mouv.push_back("incantation");
      this->_sav->cpt++;
    }
  else
    std::cout << "I have not enough food to survive during the incantation..." << std::endl;
}

void	Perso::fork()
{
  this->_time += 42;
  this->_sav->mouv.push_back("fork");
  this->_sav->cpt++;
}

void	Perso::connect_nbr()
{

}

void	Perso::dead()
{
  std::cout << "I'm dead.." << std::endl;
}

// machine à état ici
std::string	Perso::do_action()
{
  std::string	action;

  std::cout << "time = " << this->_time << std::endl;
  std::cout << "nourriture = " << this->_invent._nourriture << std::endl;
  std::cout << "client = " << this->getClient() << std::endl;

  for (std::list<std::string>::iterator tmpAction = this->_action.begin(); tmpAction != this->_action.end(); ++tmpAction)
    {
      std::cout << "Action = " << *tmpAction << std::endl;
    }
  std::cout << std::endl;
  usleep(500);
  return (action);
}

/* on a 1260 de temps au début du jeu.
On décrémente de 1 à chaque tour de boucle.
 */
void	Perso::main_loop()
{
  std::string	mouv;

  while (this->_invent._nourriture > 0)
    {
      if ((this->_time % 126) == 0)
	{
	  this->_time = 126;
	  this->_invent._nourriture--;
	}
      mouv = do_action();
      if (this->_action.size() < 10)
	{
	  //this->_action.push_back(mouv);
	}
      else
	{
	}
      if (this->_sav->cpt >= 100)
	{
	  this->_sav->mouv.pop_front();
	}
      this->_time--;
    }
}
