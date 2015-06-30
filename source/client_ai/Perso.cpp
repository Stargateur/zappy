/*
** Perso.cpp for Perso in /home/mathon_j/rendu/PSU_2014_zappy/source/client_ai
** 
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Fri Jun 19 18:57:30 2015 Jérémy MATHON
// Last update Tue Jun 30 15:47:18 2015 amoure_a
*/

#include		"Perso.hpp"

Perso::Perso(std::string team, int port, std::string ip) : Client(team, port, ip)
{
  this->_sav = new Save();
  this->_time = 0;
}

Perso::~Perso()
{
}

void			Perso::avance()
{
  this->_time += 7;
  this->_sav->mouv.push_back("avance");
  this->_sav->cpt++;
}

void			Perso::droite()
{
  this->_time += 7;
  this->_sav->mouv.push_back("droite");
  this->_sav->cpt++;
}

void			Perso::gauche()
{
  this->_time += 7;
  this->_sav->mouv.push_back("gauche");
  this->_sav->cpt++;
}

void			Perso::voir()
{
  this->_time += 7;
  this->_sav->mouv.push_back("voir");
  this->_sav->cpt++;
}

void			Perso::inventaire()
{
  this->_time += 7;
  this->_sav->mouv.push_back("inventaire");
  this->_sav->cpt++;
}

void			Perso::prend(std::string const &obj)
{
  (void)obj;
  this->_time += 7;
  this->_sav->mouv.push_back("prend");
  this->_sav->cpt++;
}

void			Perso::pose(std::string const &obj)
{
  (void)obj;
  this->_time += 7;
  this->_sav->mouv.push_back("pose");
  this->_sav->cpt++;
}

void			Perso::expulse()
{
  this->_time += 7;
  this->_sav->mouv.push_back("expulse");
  this->_sav->cpt++;
}

void			Perso::broadcast(std::string const &txt)
{
  (void)txt;
  this->_time += 7;
  this->_sav->mouv.push_back("broadcast");
  this->_sav->cpt++;
}

void			Perso::incantation()
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

void			Perso::fork()
{
  this->_time += 42;
  this->_sav->mouv.push_back("fork");
  this->_sav->cpt++;
}

void			Perso::connect_nbr()
{

}

void			Perso::dead()
{
  std::cout << "I'm dead.." << std::endl;
}

// machine à état ici
std::string		Perso::do_action()
{
  std::string		action("voir\n");

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

std::string		Perso::server_answer(std::string action)
{
  std::string		answer;
  ssize_t		ret;

  answer.resize(2048);
  std::cout << "En attente d'une réponse du serveur ..." << std::endl;
  std::cout << action << std::endl;
  if (write(this->getClient(), (const void *)action.c_str(), (size_t)action.size()) != -1)
    {
      ret = -1;
      ret = read(this->getClient(), (void *)answer.c_str(), (size_t)answer.size());
      if (ret == -1)
	{
	  std::cerr << "Error on read " << answer << std::endl;
	}
      else
	{
	  std::cout << "Réponse du serveur = " << answer <<  "nombre de caractères = " << ret << std::endl;
	}
    }
  else
    std::cerr << "Error on write in server_answer" << std::endl;
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

void		Perso::size_map_pos_ia(std::string coords)
{
  std::string	x;
  std::string	y;

  x = coords.substr(0, coords.find_first_of(" "));
  y = coords.substr(coords.find_first_of(" ") + 1, coords.length());
  this->_mapheight = atoi(y.c_str());
  this->_maplength = atoi(x.c_str());
  this->_posx = this->_mapheight / 2;
  this->_posy = this->_maplength / 2;
  std::cout << "Map X Y = " << this->_mapheight << this->_maplength << std::endl;
  std::cout << "x y = " << this->_posx << this->_posy << std::endl;
}

void		Perso::get_numclient(std::string num_client)
{
  this->_numclient = atoi(num_client.c_str());
  std::cout << "num client = " << this->_numclient << std::endl;
  exit(0);
}

void	Perso::welcome()
{
  ssize_t	res;
  std::string	welcome;
  std::string	num_client;
  std::string	coords;

  welcome.resize(100);
  res = read(this->getClient(), (void *)welcome.c_str(), 100);
  if (res != -1)
    {
      std::cout << welcome;
      res = write(this->getClient(), this->getTeamName(), (size_t)this->getTeam().size() + 1);
      if (res != -1)
	{
	  num_client.resize(20);
	  res = read(this->getClient(), (void *)num_client.c_str(), 20);
	  if (res != -1)
	    {
	      this->get_numclient(num_client);
	      coords.resize(100);
	      std::cout << "NUM_CLIENT = " << num_client;
	      res = read(this->getClient(), (void *)coords.c_str(), 100);
	      if (res != -1)
		this->size_map_pos_ia(coords);
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
