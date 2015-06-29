/*
** Perso.cpp for Perso in /home/mathon_j/rendu/PSU_2014_zappy/source/client_ai
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Fri Jun 19 18:57:30 2015 Jérémy MATHON
// Last update Mon Jun 29 16:52:20 2015 amoure_a
*/

#include	"Perso.hpp"

Perso::Perso(std::string team, int port, std::string ip) : Client(team, port, ip)
{
  this->_sav = new Save();
  this->_time = 0;
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
  std::string	action("voir");

  std::cout << "time = " << this->_time << std::endl;
  std::cout << "nourriture = " << this->_invent._nourriture << std::endl;
  std::cout << "client = " << this->getClient() << std::endl;

  std::cout << "Action = " << action << std::endl;
  /*for (std::list<std::string>::iterator tmpAction = this->_action.begin(); tmpAction != this->_action.end(); ++tmpAction)
    {
    std::cout << "Action = " << *tmpAction << std::endl;
    }*/
  std::cout << std::endl;
  usleep(500);
  return (action);
}

std::string	Perso::server_answer(std::string &mouv)
{
  std::string	answer;
  ssize_t	ret;

  std::cout << "En attente d'une réponse du serveur ..." << std::endl;
  answer.reserve(2048);
  if (write(this->getClient(), (const void *)mouv.c_str(), (size_t)mouv.size()) != -1)
    {
      ret = -1;
      answer.reserve();
      ret = read(this->getClient(), (void *)answer.c_str(), (size_t)answer.size());
      if (ret == -1 || ret == 0)
	{
	  std::cerr << "Error on read " << answer << std::endl;
	}
      else
	{
	  std::cout << "Réponse du serveur = " << answer << std::endl;
	  std::cout << "nombre de caractères = " << answer.size() << std::endl;
	}
    }
  return (answer);
}

void	Perso::execute_commands(std::string &answer, bool *death)
{
  if (answer.compare("OK") == 0)
    {
      // éxécuter commandes avance, droite, gauche, prend objet, pose objet, expulse, broadcast text, fork
    }
  else if (answer.compare("KO") == 0)
    {
      // continuer le jeu
    }
  else if (answer.compare("mort") == 0)
    {
      std::cerr << "Le joueur est mort" << std::endl;
      *death = true;
    }
  else
    {
      // envoyer les infos aux commandes voir, inventaire, incantation, connect_nbr
    }
}

const void	*Perso::getTeamName()
{
  std::string	team_name;

  team_name = this->getTeam() + "\n";
  return ((const void *)team_name.c_str());
}

void	Perso::welcome()
{
  ssize_t	res;
  char		welcome[100];
  char		num_client[20];
  char		coords[100];

  res = read(this->getClient(), (void *)welcome, 100);
  if (res != -1)
    {
      welcome[res] = '\0';
      std::cout << welcome;
      res = write(this->getClient(), this->getTeamName(), (size_t)this->getTeam().size() + 1);
      if (res != -1)
	{
	  res = read(this->getClient(), (void *)num_client, 20);
	  if (res != -1)
	    {
	      num_client[res] = '\0';
	      std::cout << "NUM_CLIENT = " << num_client;
	      res = read(this->getClient(), (void *)coords, 100);
	      if (res != -1)
		{
		  coords[res] = '\0';
		  std::cout << "X Y = " << coords;
		}
	      else
		std::cerr << "Error son X Y" << std::endl;
	    }
	  else
	    std::cerr << "Error on NUM_CLIENT" << std::endl;
	}
      else
	std::cerr << "Error on TEAL_NAME" << std::endl;
    }
  else
    std::cerr << "Error on BIENVENUE" << std::endl;
  std::cout << std::endl;
}

void	Perso::main_loop()
{
  std::string	action;
  std::string	answer;
  bool		death;

  death = false;
  while (this->_invent._nourriture > 0 && death == false)
    {
      if ((this->_time % 126) == 0)
	{
	  this->_time = 0;
	  this->_invent._nourriture--;
	}
      action = do_action(); // on fait la machine à état ici
      answer = this->server_answer(action); // envoi de la cmd au serveur et attente de la réponse (faudra faire jusque 10 envois possibles)
      this->execute_commands(answer, &death);
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
    }
}
