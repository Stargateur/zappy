//
// Other_cmds.cpp for Other_commands in /home/xila/PSU_2014_zappy
// 
// Made by amoure_a
// Login   <alix amoureux@epitech.net>
// 
// Started on  Sun Jul  5 22:50:09 2015 amoure_a
// Last update Sun Jul  5 22:50:10 2015 amoure_a
//

#include	"Perso.hpp"

int     Perso::find_number(std::string &answer, const char &char_end)
{
  size_t        pos_space;
  size_t        pos_coma;
  int           number;

  pos_space = answer.find_first_of(" ");
  answer = answer.replace(pos_space, 1, "");
  pos_coma = answer.find_first_of(char_end);
  answer = answer.replace(pos_coma, 1, "");
  number  = atoi((answer.substr(pos_space, pos_coma - pos_space)).c_str());
  return (number);
}

void                    Perso::inventaire(std::string& answer)
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
}

void                    Perso::expulse()
{
  int                   nb_player;
  int                   count = 0;
  int                   x;
  int                   y;

  this->_time += 7;
  this->_sav->mouv.push_back("expulse");
  nb_player = std::count(this->_sav->map[this->_posy][this->_posx].begin(), this->_sav\
			 ->map[this->_posy][this->_posx].end(), PLAYER);
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

void                    Perso::broadcast(std::string const &txt)
{
  (void)txt;
  this->_time += 7;
  this->_sav->mouv.push_back("broadcast");
  this->_sav->cpt++;
}

void                    Perso::incantation()
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

void                    Perso::fork()
{
  this->_time += 42;
  this->_sav->mouv.push_back("fork");
  this->_sav->cpt++;
}

void                    Perso::connect_nbr()
{

}

void                    Perso::dead()
{
  std::cout << "I'm dead.." << std::endl;
}
