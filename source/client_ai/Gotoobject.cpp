//
// Gotoobject.cpp for Gotoobjet in /home/xila/PSU_2014_zappy
// 
// Made by amoure_a
// Login   <alix amoureux@epitech.net>
// 
// Started on  Sun Jul  5 22:49:45 2015 amoure_a
// Last update Sun Jul  5 22:49:46 2015 amoure_a
//

#include	"Perso.hpp"

void			Perso::go_up(int *objy, t_way *tmpway)
{
  if (*tmpway == LEFT)
    {
      this->_action.push_back("droite\n");
      this->_action.push_back("avance\n");
      *objy -= 1;
      while (*objy > 0)
	{
	  this->_action.push_back("avance\n");
	  *objy -= 1;
	}
    }
  else if (*tmpway == RIGHT)
    {
      this->_action.push_back("gauche\n");
      this->_action.push_back("avance\n");
      *objy -=1;
      while (*objy > 0)
	{
	  this->_action.push_back("avance\n");
	  *objy -=1;
	}
    }
  else if (*tmpway == DOWN)
    {
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
    }
  else if (*tmpway == UP)
    {
      while (*objy > 0)
	{
	  this->_action.push_back("avance\n");
	  *objy -=1;
	}
    }
  *tmpway = UP;
}

void			Perso::go_down(int *objy, t_way *tmpway)
{
  if (*tmpway == LEFT)
    {
      this->_action.push_back("gauche\n");
      this->_action.push_back("avance\n");
      *objy += 1;
      while (*objy < 0)
	{
	  this->_action.push_back("avance\n");
	  *objy += 1;
	}
    }
  else if (*tmpway == RIGHT)
    {
      this->_action.push_back("droite\n");
      this->_action.push_back("avance\n");
      *objy += 1;
      while (*objy < 0)
	{
	  this->_action.push_back("avance\n");
	  *objy += 1;
	}
    }
  else if (*tmpway == UP)
    {
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
    }
  else if (*tmpway == DOWN)
    {
      while (*objy < 0)
	{
	  this->_action.push_back("avance\n");
	  *objy += 1;
	}
    }
  *tmpway = DOWN;
}

void			Perso::go_left(int *objx, t_way *tmpway)
{
  if (*tmpway == UP)
    {
      this->_action.push_back("gauche\n");
      this->_action.push_back("avance\n");
      *objx += 1;
      while (*objx < 0)
	{
	  this->_action.push_back("avance\n");
	  *objx += 1;
	}
    }
  else if (*tmpway == DOWN)
    {
      this->_action.push_back("droite\n");
      this->_action.push_back("avance\n");
      *objx += 1;
      while (*objx < 0)
	{
	  this->_action.push_back("avance\n");
	  *objx += 1;
	}
    }
  else if (*tmpway == RIGHT)
    {
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
    }
  else if (*tmpway == LEFT)
    {
      while (*objx < 0)
	{
	  this->_action.push_back("avance\n");
	  *objx += 1;
	}
    }
  *tmpway = LEFT;
}

void			Perso::go_right(int *objx, t_way *tmpway)
{
  if (*tmpway == UP)
    {
      this->_action.push_back("droite\n");
      this->_action.push_back("avance\n");
      *objx -= 1;
      while (*objx > 0)
	{
	  this->_action.push_back("avance\n");
	  *objx -= 1;
	}
    }
  else if (*tmpway == DOWN)
    {
      this->_action.push_back("gauche\n");
      this->_action.push_back("avance\n");
      *objx -= 1;
      while (*objx > 0)
	{
	  this->_action.push_back("avance\n");
	  *objx -= 1;
	}
    }
  else if (*tmpway == LEFT)
    {
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
    }
  else if (*tmpway == RIGHT)
    {
      while (*objx > 0)
	{
	  this->_action.push_back("avance\n");
	  *objx -= 1;
	}
    }
  *tmpway = RIGHT;
}

void                    Perso::go_to_obj(int *coord_obj)
{
  bool                  find = false;
  int                   objx = coord_obj[0];
  int                   objy = coord_obj[1];
  t_way			tmpway = this->_way;

  while (find == false)
    {
      if (objx > 0)
	this->go_right(&objx, &tmpway);
      else if (objx < 0)
	this->go_left(&objx, &tmpway);
      else if (objy > 0)
	this->go_up(&objy, &tmpway);
      else if (objy < 0)
	this->go_down(&objy, &tmpway);
      if ((objx == 0) && (objy == 0))
	find = true;
    }
}
