//
// Mouv.cpp for Mouv in /home/xila/unix/new_year/PSU_2014_zappy/source/client_ai
// 
// Made by amoure_a
// Login   <alix amoureux@epitech.net>
// 
// Started on  Fri Jun 19 19:13:03 2015 amoure_a
// Last update Fri Jun 19 19:42:19 2015 amoure_a
//

#include		"Mouv.h"

Mouv::Mouv(std::string action, int sens)
{
  this->action = action;
  this->sens = (Mouv::t_sens)sens;
}


Mouv::~Mouv()
{
}

std::string	Mouv::getAction() const
{
  return (this->action);
}

int		Mouv::getSens() const
{
  return (this->sens);
}
