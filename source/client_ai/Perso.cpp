/*
** Perso.cpp for Perso in /home/mathon_j/rendu/PSU_2014_zappy/source/client_ai
** 
** Made by JÃ©rÃ©my MATHON
** Login   <mathon_j@mathonj>
** 
** Started on  Fri Jun 19 18:57:30 2015 JÃ©rÃ©my MATHON
** Last update Wed Jul  1 14:14:39 2015 Jérémy MATHON
*/

#include		"Perso.hpp"

Perso::Perso(std::string team, int port, std::string ip) : Client(team, port, ip)
{
  this->_sav = new Save();
  this->_time = 0;
  this->_way = UP;
  this->_level = 1;
}

Perso::~Perso()
{
}

void			Perso::avance()
{
  this->_time += 7;
  this->_sav->mouv.push_back("avance");
  this->_sav->cpt++;
  if (this->_way == RIGHT)
    this->_posx++;
  else if (this->_way == DOWN)
    this->_posy++;
  else if (this->_way == LEFT)
    this->_posx--;
  else if (this->_way == UP)
    this->_posy--;
}

void			Perso::droite()
{
  this->_time += 7;
  this->_sav->mouv.push_back("droite");
  this->_sav->cpt++;
  if (this->_way == RIGHT)
    this->_way = DOWN;
  else if (this->_way == DOWN)
    this->_way = LEFT;
  else if (this->_way == LEFT)
    this->_way = UP;
  else if (this->_way == UP)
    this->_way = RIGHT;
}

void			Perso::gauche()
{
  this->_time += 7;
  this->_sav->mouv.push_back("gauche");
  this->_sav->cpt++;
  if (this->_way == RIGHT)
    this->_way = UP;
  else if (this->_way == DOWN)
    this->_way = RIGHT;
  else if (this->_way == LEFT)
    this->_way = DOWN;
  else if (this->_way == UP)
    this->_way = LEFT;
}

void			Perso::put_objects_in_case(int x, int y, std::string answer)
{
  int			i = 0;
  int			nb_objects =  std::count(answer.begin(), answer.end(), ' ');

  this->_sav->map[this->_posy][this->_posx].push_back(PLAYER);

  // ne gère pas le fait s'il y a plusieurs fois le même objet dans la case !
  while (i < nb_objects)
    {
      if (strstr(answer.c_str(), "joueur") != NULL)
	this->_sav->map[y][x].push_back(PLAYER);
      else if (strstr(answer.c_str(), "linemate") != NULL)
	this->_sav->map[y][x].push_back(LINEMATE);
      else if (strstr(answer.c_str(), "deraumere") != NULL)
	this->_sav->map[y][x].push_back(DERAUMERE);
      else if (strstr(answer.c_str(), "sibur") != NULL)
	this->_sav->map[y][x].push_back(SIBUR);
      else if (strstr(answer.c_str(), "mendiane") != NULL)
	this->_sav->map[y][x].push_back(MENDIANE);
      else if (strstr(answer.c_str(), "phiras") != NULL)
	this->_sav->map[y][x].push_back(PHIRAS);
      else if (strstr(answer.c_str(), "thystame") != NULL)
	this->_sav->map[y][x].push_back(THYSTAME);
      else if (strstr(answer.c_str(), "nourriture") != NULL)
	this->_sav->map[y][x].push_back(FOOD);
      i++;
    }
}

void			Perso::save_objects_in_map(std::string objects, int i)
{
  int			line = 0;
  int			column = 0;
  int			tmpcol = 0;
  int			cpt = 0;
  int			cur_num_col;
  int			cur_num_line;
  int			diff;
  int			coef_vert;

  // si dir vers le haut ou le bas
  if (this->_way == UP || this->_way == DOWN)
    {
      if (this->_way == UP)
	coef_vert = -1;
      if (this->_way == DOWN)
	coef_vert = 1;
      while (line <= (this->_level + 1))
	{
	  cur_num_line = this->_posy + ((line + 1) * coef_vert);
	  tmpcol = 0;
	  while (tmpcol <= (column))
	    {
	      if (cpt == i)
		{
		  if (tmpcol < (column / 2) ) // à gauche de '0'
		    {
		      diff = (column / 2) - tmpcol;
		      if (diff < 0)
			diff = -diff;
		      if (this->_way == UP)
			cur_num_col = this->_posx - diff;
		      if (this->_way == DOWN)
			cur_num_col = this->_posx + diff;
		    }
		  else if (tmpcol > (column / 2)) // à droite de '0'
		    {
		      diff = (column / 2) - tmpcol;
		      if (diff < 0)
			diff = -diff;
		      if (this->_way == UP)
			cur_num_col = this->_posx + diff;
		      if (this->_way == DOWN)
			cur_num_col = this->_posx - diff;
		    }
		  else // au niveau de '0'
		    cur_num_col = this->_posx;
		  this->put_objects_in_case(cur_num_col, cur_num_line, objects);
		}
	      cpt++;
	      tmpcol++;
	    }
	  column += 2;
	  line++;
	}
    }
}

void			Perso::see_map()
{
  int			x = 0;
  int			y = 0;

  std::cout << "lecture de la map !" << std::endl;
  while (y < this->_mapheight)
    {
      x = 0;
      while (x < this->_maplength)
	{
	  std::cout << this->_sav->map[y][x].back();
	  x++;
	}
      std::cout << std::endl;
      y++;
    }
  exit(0);
}

void			Perso::voir(std::string answer)
{
  int			i = 0;
  int			nb_cases;
  int			pos_first_coma;
  int			pos_second_coma;
  std::string		objects_by_case;
  
  this->_time += 7;
  this->_sav->mouv.push_back("voir");
  //std::cout << "x = " << this->_posx << " / y = " << this->_posy << std::endl;
  //std::cout << "x = " << this->_maplength << " / y = " << this->_mapheight << std::endl;
  nb_cases = std::count(answer.begin(), answer.end(), ','); 
 pos_first_coma = answer.find_first_of("{") + 1;
  while (i < nb_cases)
    {
      pos_second_coma = answer.find_first_of(",");
      objects_by_case = answer.substr(pos_first_coma, pos_second_coma - pos_first_coma);
      //std::cout << "i = " << i << std::endl;
      this->save_objects_in_map(objects_by_case, i);
      answer = answer.replace(pos_second_coma, 1, "");
      pos_first_coma = pos_second_coma;
      i++;
    }
  pos_second_coma = answer.find_first_of("}");
  objects_by_case = answer.substr(pos_first_coma, pos_second_coma - pos_first_coma);
  this->save_objects_in_map(objects_by_case, i);
  //exit(0);
  this->see_map();
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

// machine a  etat ici
std::string		Perso::do_action()
{
  std::string		action("voir\n");

  std::cout << "Action = " << action;
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
	  std::cout << "Reponse du serveur = " << answer <<  "nombre de caracteres = " << ret << std::endl;
	  answer.resize(ret);
	}
    }
  else
    std::cerr << "Error on write in server_answer" << std::endl;
  return (answer);
}

//{nourriture 1, linemate 0}

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

void	Perso::get_inventory(std::string answer)
{
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

void	Perso::execute_commands(std::string &answer, bool *death, std::string &action)
{
  if (answer.compare("OK\n") == 0)
    {
      if (action.compare("avance\n") == 0)
	this->avance();
      if (action.compare("droite\n") == 0)
	this->droite();
      if (action.compare("gauche\n") == 0)
	this->gauche();
      if (action.compare("prend objet\n") == 0)
	this->prend("test");
      if (action.compare("pose objet\n") == 0)
	this->pose("test");
      if (action.compare("expulse\n") == 0)
	this->expulse();
      if (action.compare("broadcast\n") == 0)
	this->broadcast("ceci est un message code\n");
      if (action.compare("fork\n") == 0)
	this->fork();
      // Excuter commandes avance, droite, gauche, prend objet, pose objet, expulse, broadcast text, fork
    }
  else if (answer.compare("KO\n") == 0)
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
	{
	  this->voir(answer);
	  // comment faire par rapport au placement des cases
	}
      else if (action.compare("inventaire\n") == 0)
	{
	  this->get_inventory(answer);
	}
      else if (action.compare("incantation\n") == 0)
	{

	}
      else if (action.compare("connect_nbr\n") == 0)
	{
	  this->_nbunusedslots = atoi(answer.c_str());
	  std::cout << "Nb slots non utilises : " << this->_nbunusedslots << std::endl;
	  exit(0);
	}
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
  int		i;
  int		j;

  i = 0;
  x = coords.substr(0, coords.find_first_of(" "));
  y = coords.substr(coords.find_first_of(" ") + 1, coords.length());
  this->_mapheight = atoi(y.c_str());
  this->_maplength = atoi(x.c_str());
  this->_posx = this->_maplength / 2;
  this->_posy = this->_mapheight / 2;
  this->_sav->map = std::vector< std::vector< std::list <t_case> > > (this->_mapheight);
  while (i < this->_mapheight)
    {
      this->_sav->map[i] = std::vector<std::list <t_case> > (this->_maplength);
      j = 0;
      while (j < this->_maplength)
	{
	  this->_sav->map[i][j].push_back(NONE);
	  j++;
	}
      i++;
    }
}

void		Perso::get_numclient(std::string num_client)
{
  this->_numclient = atoi(num_client.c_str());
  //std::cout << "num client = " << this->_numclient << std::endl;
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
      action = do_action(); // on fait la machine Ã  Ã©tat ici
      answer = this->server_answer(action); // envoi de la cmd au serveur et attente de la rÃ©ponse (faudra faire jusque 10 envois possibles)
      this->execute_commands(answer, &death, action);
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
      sleep(1);
    }
}
