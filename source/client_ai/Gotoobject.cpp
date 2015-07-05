#include	"Perso.hpp"

void			Perso::go_up(int *objx, int *objy)
{
  std::cout << "On va en haut !" << std::endl;
  if (this->_way == LEFT)
    {
      //std::cout << "A droite !" << std::endl;
      this->_action.push_back("droite\n");
      *objy -= 1;
      while (*objy > 0)
	{
	  this->_action.push_back("avance\n");
	  //std::cout << "Devant !" << std::endl;
	  *objy -= 1;
	}
    }
  else if (this->_way == RIGHT)
    {
      //std::cout << "A gauche !" << std::endl;
      this->_action.push_back("gauche\n");
      *objy -=1;
      while (*objy > 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objy -=1;
	}
    }
  else if (this->_way == DOWN)
    {
      /*std::cout << "A gauche !" << std::endl;
      std::cout << "A gauche !" << std::endl;*/
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
      *objy -=1;
      *objx +=1;
    }
  else if (this->_way == UP)
    {
      while (*objy > 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objy -=1;
	}
    }
  this->_way = UP;
}

void			Perso::go_down(int *objx, int *objy)
{
  std::cout << "On va en bas !" << std::endl;
  if (this->_way == LEFT)
    {
      //std::cout << "A gauche !" << std::endl;
      this->_action.push_back("gauche\n");
      *objy += 1;
      while (*objy < 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objy += 1;
	}
    }
  else if (this->_way == RIGHT)
    {
      //std::cout << "A droite !" << std::endl;
      this->_action.push_back("droite\n");
      *objy += 1;
      while (*objy < 0)
	{
	  //std::cout << "Avance !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objy += 1;
	}
    }
  else if (this->_way == UP)
    {
      /*std::cout << "A gauche !" << std::endl;
	std::cout << "A gauche !" << std::endl;*/
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
      *objy += 1;
      *objx -= 1;
    }
  else if (this->_way == DOWN)
    {
      while (*objy < 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objy += 1;
	}
    }
  this->_way = DOWN;
}

void			Perso::go_left(int *objx, int *objy)
{
  std::cout << "On va a gauche !" << std::endl;
  if (this->_way == UP)
    {
      //std::cout << "A gauche !" << std::endl;
      this->_action.push_back("gauche\n");
      *objx += 1;
      while (*objx < 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objx += 1;
	}
    }
  else if (this->_way == DOWN)
    {
      //std::cout << "A droite !" << std::endl;
      this->_action.push_back("droite\n");
      *objx += 1;
      while (*objx < 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objx += 1;
	}
    }
  else if (this->_way == RIGHT)
    {
      /*std::cout << "A gauche !" << std::endl;
      std::cout << "A gauche !" << std::endl;*/
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
      *objx += 1;
      *objy -= 1;
    }
  else if (this->_way == LEFT)
    {
      while (*objx < 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objx += 1;
	}
    }
  this->_way = LEFT;
}

void			Perso::go_right(int *objx, int *objy)
{
  std::cout << "On va a droite !" << std::endl;
  if (this->_way == UP)
    {
      //std::cout << "A droite !" << std::endl;
      this->_action.push_back("droite\n");
      *objx -= 1;
      while (*objx > 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objx -= 1;
	}
    }
  else if (this->_way == DOWN)
    {
      //std::cout << "A gauche !" << std::endl;
      this->_action.push_back("gauche\n");
      *objx -= 1;
      while (*objx > 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objx -= 1;
	}
    }
  else if (this->_way == LEFT)
    {
      /*std::cout << "A gauche !" << std::endl;
      std::cout << "A gauche !" << std::endl;*/
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
      *objx -= 1;
      *objy += 1;
    }
  else if (this->_way == RIGHT)
    {
      while (*objx > 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objx -= 1;
	}
    }
  this->_way = RIGHT;
}

void                    Perso::go_to_obj(int *coord_obj)
{
  bool                  find = false;
  int                   objx = coord_obj[0];
  int                   objy = coord_obj[1];
  int                   tmpx = this->_posx;
  int                   tmpy = this->_posy;

  std::cout << "Objx : " << coord_obj[0] << " Objy : " << coord_obj[1] << std::endl;
  std::cout << "Dir = " << this->_way << std::endl;
  /*if (this->_way == UP)
    {
      objx = this->_posx + coord_obj[0];
      objy = this->_posy + coord_obj[1];
    }
  if (this->_way == DOWN)
    {
      objx = this->_posx - coord_obj[0];
      objy = this->_posy - coord_obj[1];
    }
  /*if (this->_way == LEFT)
    {
    objx = this->_posx - coord_obj[1];
    objy = this->_posy + coord_obj[0];
    }
    if (this->_way == RIGHT)
    {
    objx = this->_posx + coord_obj[0];
    objy = this->_posy - coord_obj[1];
    }*/

  while (find == false)
    {
      if (objx > 0) // obj a droite 
	this->go_right(&objx, &objy);
      else if (objx < 0)
	this->go_left(&objx, &objy);
      else if (objy > 0)
	this->go_up(&objx, &objy);
      else if (objy < 0)
	this->go_down(&objx, &objy);
      if ((objx == 0) && (objy == 0))
	{
	  //std::cout << "Fini !" << std::endl;
	  //std::cout << "On est en " << tmpx << "/" << tmpy << std::endl;
	  find = true;
	}
    }
}
