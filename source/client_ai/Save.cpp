//
// Save.cpp for Save in /home/xila/unix/new_year/PSU_2014_zappy/source/client_ai
// 
// Made by amoure_a
// Login   <alix amoureux@epitech.net>
// 
// Started on  Fri Jun 19 19:00:59 2015 amoure_a
// Last update Fri Jun 19 19:51:56 2015 amoure_a
//

#include		"Save.h"

Save::Save()
{
}

Save::~Save()
{
}

void		Save::addItem(std::string action, int sens)
{
  Mouv		mouv(action, sens);

  this->mouv.push_back(mouv);
}

void		Save::removeItem()
{
  this->mouv.pop_back();
}

/* à supprimer avant la fin du rendu */
void		Save::seeList()
{
  std::list<Mouv>::iterator	it = this->mouv.begin();

  while (it != this->mouv.end())
    {
      std::cout << it->getAction() << " " << it->getSens() << std::endl;
      it++;
    }
}
