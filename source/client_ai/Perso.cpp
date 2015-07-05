/*
** Perso.cpp for Perso in /home/mathon_j/rendu/PSU_2014_zappy/source/client_ai
** 
** Made by JÃ©rÃ©my MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Fri Jun 19 18:57:30 2015 JÃ©rÃ©my MATHON
// Last update Fri Jul  3 16:07:07 2015 amoure_a
*/

#include		"Perso.hpp"

Perso::Perso(std::string team, int port, std::string ip) : Client(team, port, ip)
{
  this->_sav = new Save();
  this->_time = 0;
  this->_way = LEFT;
  this->_level = 1;
  this->_see = false;
}

Perso::~Perso()
{
}

int			*Perso::find_obj_in_map(const t_case &obj)
{
  int			*pos_obj = new (int [2]);
  int			x = -2;
  int			y = -2;
  int			posx;
  int			posy;
  std::list<t_case>::iterator	it;

  pos_obj[0] = -42;
  pos_obj[1] = -42;
  for (it = this->_sav->map[this->_posy][this->_posx].begin(); it != this->_sav->map[this->_posy][this->_posx].end(); ++it)
    {
      if (*it == obj)
	{
	  pos_obj[0] = 0;
	  pos_obj[1] = 0;
	  return (pos_obj);
	}
    }
  while (y < 3)
    {
      x = -2;
      while (x < 3)
	{
	  posy = this->_posy + y;
	  if (posy < 0)
	    posy = (this->_mapheight) + posy;
	  else if (posy > (this->_mapheight - 1))
	    posy = posy - (this->_mapheight - 1);
	  posx = this->_posx + x;
	  if (posx < 0)
	    posx = (this->_maplength) + posx;
	  else if (posx > (this->_maplength - 1))
	    posx = posx - (this->_maplength - 1);
	  if (this->_sav->map[posy][posx].back() != NONE)
	    {
	      for (it = this->_sav->map[posy][posx].begin(); it != this->_sav->map[posy][posx].end(); ++it)
		{
		  if (*it == obj)
		    {
		      pos_obj[0] = x;
		      pos_obj[1] = -y;
		      return (pos_obj);
		    }
		}
	    }
	  x++;
	}
      y++;
    }
  return (pos_obj);
}

void			Perso::search_food()
{
  int			*coords_obj_in_map;

  coords_obj_in_map = this->find_obj_in_map(FOOD);
  if (coords_obj_in_map[0] == -42)
    {
      this->_action.push_back("avance\n");
      this->_action.push_back("voir\n");
    }
  else
    {
      if (this->_posx == coords_obj_in_map[0] && this->_posy == coords_obj_in_map[1])
	this->_action.push_back("prend nourriture\n");
      else
	{
	  this->go_to_obj(coords_obj_in_map);
	  this->_action.push_back("prend nourriture\n");
	}
    }  
}

void			Perso::search_linemate()
{
  int			*coords_obj_in_map;

  coords_obj_in_map = this->find_obj_in_map(LINEMATE);
  if (coords_obj_in_map[0] == -42)
    {
      this->_action.push_back("avance\n");
      this->_action.push_back("voir\n");
    }
  else
    {
      if (this->_posx == coords_obj_in_map[0] && this->_posy == coords_obj_in_map[1])
	this->_action.push_back("prend linemate\n");
      else
	{
	  if (this->_see == false)
	    {
	      this->go_to_obj(coords_obj_in_map);
	      this->_action.push_back("incantation\n");
	    }
	  else
	    {
	      this->_sav->map[this->_posy][this->_posx].remove(LINEMATE);
	      this->_action.push_back("avance\n");
	    }
	}
    }
}

void			Perso::find_actions()
{
  if (this->_level == 1)
    {
      if (this->_invent._nourriture < 10)
	this->search_food();
      else if (this->_invent._linemate == 0)
	this->search_linemate();
    }
  else if (this->_level == 2)
    {
      std::cout << "On est au level 2 !" << std::endl;
      this->_action.push_back("avance\n");
    }
}

std::string		Perso::server_answer(const std::string& action)
{
  std::string		answer;
  ssize_t		ret;

  answer.resize(2048);
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
	  std::cout << "Reponse du serveur = " << answer << std::endl << std::endl;
	  answer.resize(ret);
	}
    }
  else
    std::cerr << "Error on write in server_answer" << std::endl;
  return (answer);
}

void	Perso::execute_commands(std::string &answer, bool *death, std::string &action)
{
  std::list<std::string>::iterator	it;

  this->_see = false;
  if (answer.compare("ok\n") == 0 || answer.compare("OK\n") == 0)
    {
      if (action.compare("avance\n") == 0)
	this->avance();
      if (action.compare("droite\n") == 0)
	this->droite();
      if (action.compare("gauche\n") == 0)
	this->gauche();
      if (action.compare(0, 5, "prend") == 0)
	this->prend(action.substr(6, action.size() - 6));
      if (action.compare(0, 4, "pose") == 0)
	this->pose(action.substr(5, action.size() - 5));
      if (action.compare("expulse\n") == 0)
	this->expulse();
      if (action.compare("broadcast\n") == 0)
	this->broadcast("ceci est un message code\n"); // faire broadcast !
      if (action.compare("fork\n") == 0)
	this->fork();
    }
  else if (answer.compare("KO\n") == 0 || answer.compare("ko\n") == 0)
    {
      if (action.compare("incantation\n") == 0)
	this->_see = true;
    }
  else if (answer.compare("mort\n") == 0)
    {
      std::cerr << "Le joueur est mort" << std::endl;
      *death = true;
    }
  else
    {
      if (action.compare("voir\n") == 0)
	this->voir(answer);
      else if (action.compare("inventaire\n") == 0)
	this->inventaire(answer);
      else if (action.compare("incantation\n") == 0)
	this->incantation();
      else if (action.compare("connect_nbr\n") == 0) // faire connect_nbr !
	{
	  this->_nbunusedslots = atoi(answer.c_str());
	}
    }
  it = std::find(this->_action.begin(), this->_action.end(), action);
  this->_action.erase(it);
}

void	Perso::main_loop()
{
  std::string	answer;
  bool		death;
  std::list<std::string>::iterator	it;
  int		num_item;

  death = false;
  while (this->_invent._nourriture > 0 && death == false)
    {
      if ((this->_time % 126) == 0)
	{
	  this->_time = 0;
	  this->_invent._nourriture--;
	}
      if (this->_action.size() < 10)
	{
	  find_actions();
	  num_item = 0;
	  for (it = this->_action.begin(); (it != this->_action.end() || this->_action.size() > 0); ++it)
	    {
	      if (num_item > 0)
		--it;
	      std::cout << "Action = " << *it;
	      answer = this->server_answer(*it);
	      this->execute_commands(answer, &death, *it);
	      it = this->_action.begin();
	      std::cout << "Nb items dans liste : " << this->_action.size() << std::endl;
	      num_item++;
	    }
	  this->_action.clear();
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
