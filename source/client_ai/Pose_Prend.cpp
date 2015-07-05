//
// Pose_Prend.cpp for Pose_Prend in /home/xila/PSU_2014_zappy
// 
// Made by amoure_a
// Login   <alix amoureux@epitech.net>
// 
// Started on  Sun Jul  5 22:50:25 2015 amoure_a
// Last update Sun Jul  5 22:50:26 2015 amoure_a
//

#include		"Perso.hpp"

void                    Perso::prend(std::string const &obj)
{
  std::list<t_case>::iterator   it;

  this->_sav->mouv.push_back("prend");
  this->_time += 7;
  if (obj.compare(0, 9, "linemate\n") == 0)
    {
      it = std::find(this->_sav->map[this->_posy][this->_posx].begin(), this->_sav->map[this->_posy][this->_posx].end(), LINEMATE);
      this->_sav->map[this->_posy][this->_posx].erase(it);
      this->_invent._linemate++;
    }
  if (obj.compare(0, 10, "deraumere\n") == 0)
    {
      it = std::find(this->_sav->map[this->_posy][this->_posx].begin(), this->_sav->map[this->_posy][this->_posx].end(), DERAUMERE);
      this->_sav->map[this->_posy][this->_posx].erase(it);
      this->_invent._deraumere++;
    }
  if (obj.compare(0, 6, "sibur\n") == 0)
    {
      it = std::find(this->_sav->map[this->_posy][this->_posx].begin(), this->_sav->map[this->_posy][this->_posx].end(), SIBUR);
      this->_sav->map[this->_posy][this->_posx].erase(it);
      this->_invent._sibur++;
    }
  if (obj.compare(0, 9, "mendiane\n") == 0)
    {
      it = std::find(this->_sav->map[this->_posy][this->_posx].begin(), this->_sav->map[this->_posy][this->_posx].end(), MENDIANE);
      this->_sav->map[this->_posy][this->_posx].erase(it);
      this->_invent._mendiane++;
    }
  if (obj.compare(0, 7, "phiras\n") == 0)
    {
      it = std::find(this->_sav->map[this->_posy][this->_posx].begin(), this->_sav->map[this->_posy][this->_posx].end(), PHIRAS);
      this->_sav->map[this->_posy][this->_posx].erase(it);
      this->_invent._phiras++;
    }
  if (obj.compare(0, 9, "thystame\n") == 0)
    {
      it = std::find(this->_sav->map[this->_posy][this->_posx].begin(), this->_sav->map[this->_posy][this->_posx].end(), THYSTAME);
      this->_sav->map[this->_posy][this->_posx].erase(it);
      this->_invent._thystame++;
    }
  if (obj.compare(0, 11, "nourriture\n") == 0)
    {
      it = std::find(this->_sav->map[this->_posy][this->_posx].begin(), this->_sav->map[this->_posy][this->_posx].end(), FOOD);
      this->_sav->map[this->_posy][this->_posx].erase(it);
      this->_invent._nourriture++;
    }

  this->_sav->cpt++;
}

void                    Perso::pose(std::string const &obj)
{
  this->_time += 7;
  this->_sav->mouv.push_back("pose");
  if (obj.compare(0, 9, "linemate\n") == 0)
    {
      this->_sav->map[this->_posy][this->_posx].push_back(LINEMATE);
      this->_invent._linemate--;
    }
  if (obj.compare(0, 10, "deraumere\n") == 0)
    {
      this->_sav->map[this->_posy][this->_posx].push_back(DERAUMERE);
      this->_invent._deraumere--;
    }
  if (obj.compare(0, 6, "sibur\n") == 0)
    {
      this->_sav->map[this->_posy][this->_posx].push_back(SIBUR);
      this->_invent._sibur--;
    }
  if (obj.compare(0, 9, "mendiane\n") == 0)
    {
      this->_sav->map[this->_posy][this->_posx].push_back(MENDIANE);
      this->_invent._mendiane--;
    }
  if (obj.compare(0, 7, "phiras\n") == 0)
    {
      this->_sav->map[this->_posy][this->_posx].push_back(PHIRAS);
      this->_invent._phiras--;
    }
  if (obj.compare(0, 9, "thystame\n") == 0)
    {
      this->_sav->map[this->_posy][this->_posx].push_back(THYSTAME);
      this->_invent._thystame--;
    }
  if (obj.compare(0, 11, "nourriture\n") == 0)
    {
      this->_sav->map[this->_posy][this->_posx].push_back(FOOD);
      this->_invent._nourriture--;
    }
  this->_sav->map[this->_posy][this->_posx].remove(NONE);
  this->_sav->cpt++;
}
