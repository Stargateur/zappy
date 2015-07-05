#include	"Perso.hpp"

void			Perso::go_up(int *objx, int *objy, t_way *tmpway)
{
  //std::cout << "On va en haut !" << std::endl;
  if (*tmpway == LEFT)
    {
      //std::cout << "A droite !" << std::endl;
      this->_action.push_back("droite\n");
      this->_action.push_back("avance\n");
      *objy -= 1;
      while (*objy > 0)
	{
	  this->_action.push_back("avance\n");
	  //std::cout << "Devant !" << std::endl;
	  *objy -= 1;
	}
    }
  else if (*tmpway == RIGHT)
    {
      //std::cout << "A gauche !" << std::endl;
      this->_action.push_back("gauche\n");
      this->_action.push_back("avance\n");
      *objy -=1;
      while (*objy > 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objy -=1;
	}
    }
  else if (*tmpway == DOWN)
    {
      /*std::cout << "A gauche !" << std::endl;
      std::cout << "A gauche !" << std::endl;*/
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
      //*objy -=1;
      //*objx +=1;
    }
  else if (*tmpway == UP)
    {
      while (*objy > 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objy -=1;
	}
    }
  *tmpway = UP;
}

void			Perso::go_down(int *objx, int *objy, t_way *tmpway)
{
  //std::cout << "On va en bas !" << std::endl;
  if (*tmpway == LEFT)
    {
      //std::cout << "A gauche !" << std::endl;
      this->_action.push_back("gauche\n");
      this->_action.push_back("avance\n");
      *objy += 1;
      while (*objy < 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objy += 1;
	}
    }
  else if (*tmpway == RIGHT)
    {
      //std::cout << "A droite !" << std::endl;
      this->_action.push_back("droite\n");
      this->_action.push_back("avance\n");
      *objy += 1;
      while (*objy < 0)
	{
	  //std::cout << "Avance !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objy += 1;
	}
    }
  else if (*tmpway == UP)
    {
      /*std::cout << "A gauche !" << std::endl;
	std::cout << "A gauche !" << std::endl;*/
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
      //*objy += 1;
      //*objx -= 1;
    }
  else if (*tmpway == DOWN)
    {
      while (*objy < 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objy += 1;
	}
    }
  *tmpway = DOWN;
}

void			Perso::go_left(int *objx, int *objy, t_way *tmpway)
{
  //std::cout << "On va a gauche !" << std::endl;
  if (*tmpway == UP)
    {
      //std::cout << "A gauche !" << std::endl;
      this->_action.push_back("gauche\n");
      this->_action.push_back("avance\n");
      *objx += 1;
      while (*objx < 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objx += 1;
	}
    }
  else if (*tmpway == DOWN)
    {
      //std::cout << "A droite !" << std::endl;
      this->_action.push_back("droite\n");
      this->_action.push_back("avance\n");
      *objx += 1;
      while (*objx < 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objx += 1;
	}
    }
  else if (*tmpway == RIGHT)
    {
      /*std::cout << "A gauche !" << std::endl;
      std::cout << "A gauche !" << std::endl;*/
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
      //*objx += 1;
      //*objy -= 1;
    }
  else if (*tmpway == LEFT)
    {
      while (*objx < 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objx += 1;
	}
    }
  *tmpway = LEFT;
}

void			Perso::go_right(int *objx, int *objy, t_way *tmpway)
{
  //std::cout << "On va a droite !" << std::endl;
  if (*tmpway == UP)
    {
      //std::cout << "A droite !" << std::endl;
      this->_action.push_back("droite\n");
      this->_action.push_back("avance\n");
      *objx -= 1;
      while (*objx > 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objx -= 1;
	}
    }
  else if (*tmpway == DOWN)
    {
      //std::cout << "A gauche !" << std::endl;
      this->_action.push_back("gauche\n");
      this->_action.push_back("avance\n");
      *objx -= 1;
      while (*objx > 0)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *objx -= 1;
	}
    }
  else if (*tmpway == LEFT)
    {
      /*std::cout << "A gauche !" << std::endl;
      std::cout << "A gauche !" << std::endl;*/
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
      //*objx -= 1;
      //*objy += 1;
    }
  else if (*tmpway == RIGHT)
    {
      while (*objx > 0)
	{
	  //std::cout << "Devant !" << std::endl;
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

  std::cout << "IA a obj : x = " << objx << " y = " << objy << std::endl;
  while (find == false)
    {
      if (objx > 0)
	this->go_right(&objx, &objy, &tmpway);
      else if (objx < 0)
	this->go_left(&objx, &objy, &tmpway);
      else if (objy > 0)
	this->go_up(&objx, &objy, &tmpway);
      else if (objy < 0)
	this->go_down(&objx, &objy, &tmpway);
      if ((objx == 0) && (objy == 0))
	{
	  std::cout << "Fini !" << std::endl;
	  find = true;
	}
    }
}
