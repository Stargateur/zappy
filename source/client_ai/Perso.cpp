/*
** Perso.cpp for Perso in /home/mathon_j/rendu/PSU_2014_zappy/source/client_ai
** 
** Made by JÃ©rÃ©my MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Fri Jun 19 18:57:30 2015 JÃ©rÃ©my MATHON
// Last update Fri Jul  3 14:46:39 2015 amoure_a
*/

#include		"Perso.hpp"

Perso::Perso(std::string team, int port, std::string ip) : Client(team, port, ip)
{
  this->_sav = new Save();
  this->_time = 0;
  this->_way = RIGHT;
  this->_level = 1;
}

Perso::~Perso()
{
}

void			Perso::see_map()
{
  int			x = 0;
  int			y = 0;

  std::cout << "Pos du joueur : x : " << this->_posx << " y : " << this->_posy << std::endl;
  std::cout << "lecture de la map !" << std::endl;
  while (y < this->_mapheight)
    {
      x = 0;
      while (x < this->_maplength)
	{
	  if (this->_sav->map[y][x].back() != NONE)
	    {
	      std::cout << "x : " << x << " y : " << y << std::endl;
	      std::cout << "nombre d'objets : " << this->_sav->map[y][x].size() << std::endl;
	      //std::cout << this->_sav->map[y][x].back(); 
	    }
	  x++;
	}
      //std::cout << std::endl;
      y++;
    }
  exit(0);
}

int	Perso::find_number(std::string &answer, char char_end)
{
  size_t	pos_space;
  size_t	pos_coma;
  int		number;

  pos_space = answer.find_first_of(" ");
  answer = answer.replace(pos_space, 1, "");
  pos_coma = answer.find_first_of(char_end);
  answer = answer.replace(pos_coma, 1, "");
  number  = atoi((answer.substr(pos_space, pos_coma - pos_space)).c_str());
  return (number);
}

void			Perso::inventaire(std::string answer)
{
  this->_time += 7;
  this->_sav->mouv.push_back("inventaire");
  this->_sav->cpt++;

  this->_invent._nourriture = this->find_number(answer, ',');
  this->_invent._linemate = this->find_number(answer, ',');
  this->_invent._deraumere = this->find_number(answer, ',');
  this->_invent._sibur = this->find_number(answer, ',');
  this->_invent._mendiane = this->find_number(answer, ',');
  this->_invent._phiras = this->find_number(answer, ',');
  this->_invent._thystame = this->find_number(answer, '}');
  std::cout << "Nourriture : " << this->_invent._nourriture << std::endl;
  std::cout << "linemate : " << this->_invent._linemate << std::endl;
  std::cout << "deraumere : " << this->_invent._deraumere << std::endl;
  std::cout << "sibur : " << this->_invent._sibur << std::endl;
  std::cout << "mendiane : " << this->_invent._mendiane << std::endl;
  std::cout << "phyras : " << this->_invent._phiras << std::endl;
  std::cout << "thystame : " << this->_invent._thystame << std::endl;
}

void			Perso::expulse()
{
  int			nb_player;
  int			count = 0;
  int			x;
  int			y;

  this->_time += 7;
  this->_sav->mouv.push_back("expulse");
  nb_player = std::count(this->_sav->map[this->_posy][this->_posx].begin(), this->_sav->map[this->_posy][this->_posx].end(), PLAYER);
  this->_sav->map[this->_posy][this->_posx].remove(PLAYER);
  if (this->_way == UP)
    {
      y = this->_posy - 1;
      x = this->_posx;
    }
  if (this->_way == DOWN)
    {
      y = this->_posy + 1;
      x = this->_posx;
    }
  if (this->_way == LEFT)
    {
      y = this->_posy;
      x = this->_posx - 1;
    }
  if (this->_way == RIGHT)
    {
      y = this->_posy;
      x = this->_posx + 1;
    }
  if (x == -1)
    x = this->_maplength - 1;
  if (x == this->_maplength)
    x = 0;
  if (y == -1)
    y = this->_mapheight - 1;
  if (y == this->_mapheight)
    y = 0;
  this->_sav->cpt++;
  while (count < nb_player)
    {
      this->_sav->map[this->_posy][this->_posx].push_back(PLAYER);
      count++;
    }
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
      this->_level++;
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


int			*Perso::find_obj_in_map(t_case obj)
{
  int			*pos_obj = new (int [2]);
  int			x = - 2;
  int			y = - 2;
  int			posx;
  int			posy;
  std::list<t_case>::iterator	it;

  pos_obj[0] = -1;
  pos_obj[1] = -1;
  while (y < 2)
    {
      posy = this->_posy + y;
      if (posy < 0)
	posy = (this->_mapheight - 1) + posy;
      if (posy > (this->_mapheight - 1))
	posy = posy - (this->_mapheight - 1);
      x = -2;
      while (x < 2)
	{
	  posx = this->_posx + x;
	  if (posx < 0)
	    posx = (this->_maplength - 1) + posx;
	  if (posx > (this->_maplength - 1))
	    posx = posx - (this->_maplength - 1);
	  it = std::find(this->_sav->map[posy][posx].begin(), this->_sav->map[posy][posx].end(), obj);
	  if (it != this->_sav->map[posy][posx].end())
	    {
	      pos_obj[0] = posx;
	      pos_obj[1] = posy;
	      std::cout << "Element trouve !" << std::endl;
	    }
	  x++;
	}
      y++;
    }
  return ((int *)pos_obj);
}

// machine a etat ici => push_back plusieurs cmds
void			Perso::find_actions()
{
  int			*coords_obj_in_map;

  if (this->_level == 1)
    {
      // chercher FOOD
      if (this->_invent._nourriture < 10)
	{
	  // chercher de la nourriture sur un carre de 4*4
	  coords_obj_in_map = this->find_obj_in_map(FOOD);
	  if (coords_obj_in_map[0] == -1)
	    {
	      this->_action.push_back("avance\n");
	      this->_action.push_back("voir\n");
	    }
	  else
	    {
	      // 1) on est deja dessus
	      // 2) on se dirige vers avec gauche droite avance
	      if (this->_posx == coords_obj_in_map[0] && this->_posy == coords_obj_in_map[1])
		{
		  this->_action.push_back("prend\n");
		}
	      else
		{
		  
		}
	    }
	}
    }
  usleep(500);
}

std::string		Perso::server_answer(std::string action)
{
  std::string		answer;
  ssize_t		ret;

  answer.resize(2048);
  std::cout << "En attente d'une reponse du serveur ..." << std::endl;
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
	this->broadcast("ceci est un message code\n");
      if (action.compare("fork\n") == 0)
	this->fork();
    }
  else if (answer.compare("KO\n") == 0 || answer.compare("ko\n") == 0)
    {
      // continuer le jeu
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
      else if (action.compare("connect_nbr\n") == 0)
	{
	  this->_nbunusedslots = atoi(answer.c_str());
	  std::cout << "Nb slots non utilises : " << this->_nbunusedslots << std::endl;
	}
      // envoyer les infos aux commandes voir, inventaire, incantation, connect_nbr
    }
  it = std::find(this->_action.begin(), this->_action.end(), action);
  this->_action.erase(it);
}

void	Perso::main_loop()
{
  std::string	answer;
  bool		death;
  std::string	last_action;

  death = false;
  while (this->_invent._nourriture > 0 && death == false)
    {
      std::cout << "Taille list actions :" << this->_action.size() << std::endl;
      if ((this->_time % 126) == 0)
	{
	  this->_time = 0;
	  this->_invent._nourriture--;
	}
      if (this->_action.size() < 10)
	{
	  find_actions();
	  last_action = this->_action.back();
	  //this->_action.push_back(action);
	  answer = this->server_answer(last_action);
	  this->execute_commands(answer, &death, last_action);
	}
      else
	{
	}
      if (this->_sav->cpt >= 100)
	{
	  this->_sav->mouv.pop_front();
	}
      sleep(1);
    }
}
