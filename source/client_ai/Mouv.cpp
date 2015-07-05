//
// Mouv.cpp for Mouv in /home/xila/unix/new_year/PSU_2014_zappy/source/client_ai
// 
// Made by amoure_a
// Login   <alix amoureux@epitech.net>
// 
// Started on  Fri Jun 19 19:13:03 2015 amoure_a
// Last update Fri Jun 19 19:42:19 2015 amoure_a
//

#include		"Perso.hpp"

void                    Perso::avance()
{
  this->_time += 7;
  this->_sav->mouv.push_back("avance");
  this->_sav->cpt++;
  if (this->_way == RIGHT)
    {
      this->_posx++;
    }
  else if (this->_way == DOWN)
    {
      this->_posy++;
    }
  else if (this->_way == LEFT)
    {
      this->_posx--;
    }
  else if (this->_way == UP)
    {
      this->_posy--;
    }

  if (this->_posx < 0)
    this->_posx = this->_maplength - 1;
  else if (this->_posx == this->_maplength)
    this->_posx = 0;
  else if (this->_posy < 0)
    this->_posy = this->_mapheight - 1;
  else if (this->_posy == this->_mapheight)
    this->_posy = 0;
}

void                    Perso::droite()
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

void                    Perso::gauche()
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
