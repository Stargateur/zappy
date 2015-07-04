#include	"Perso.hpp"

void			Perso::go_up(int *tmpy, int *tmpx, int *objy)
{
  //std::cout << "On va en haut !" << std::endl;
  if (this->_way == LEFT)
    {
      //std::cout << "A droite !" << std::endl;
      this->_action.push_back("droite\n");
      this->_way = UP;
      *tmpy += 1;
      while (*tmpy < *objy)
	{
	  this->_action.push_back("avance\n");
	  //std::cout << "Devant !" << std::endl;
	  *tmpy+= 1;
	}
    }
  else if (this->_way == RIGHT)
    {
      //std::cout << "A gauche !" << std::endl;
      this->_action.push_back("gauche\n");
      this->_way = UP;
      *tmpy +=1;
      while (*tmpy < *objy)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *tmpy +=1;
	}
    }
  else if (this->_way == DOWN)
    {
      /*std::cout << "A gauche !" << std::endl;
      std::cout << "A gauche !" << std::endl;
      std::cout << "A gauche !" << std::endl;*/
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
      this->_way = LEFT;
      *tmpy +=1;
    }
  else if (this->_way == UP)
    {
      while (*tmpy < *objy)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *tmpy +=1;
	}
    }

}

void			Perso::go_down(int *tmpy, int *tmpx, int *objy)
{
  //std::cout << "On va en bas !" << std::endl;
  if (this->_way == LEFT)
    {
      //std::cout << "A gauche !" << std::endl;
      this->_action.push_back("gauche\n");
      this->_way = DOWN;
      *tmpy -= 1;
      while (*tmpy > *objy)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *tmpy -= 1;
	}
    }
  else if (this->_way == RIGHT)
    {
      //std::cout << "A droite !" << std::endl;
      this->_action.push_back("droite\n");
      this->_way = DOWN;
      *tmpy -= 1;
      while (*tmpy > *objy)
	{
	  *tmpy -= 1;
	}
    }
  else if (this->_way == UP)
    {
      /*std::cout << "A gauche !" << std::endl;
      std::cout << "A gauche !" << std::endl;
      std::cout << "A gauche !" << std::endl;*/
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
      this->_way = RIGHT;
      *tmpy -= 1;
    }
  else if (this->_way == DOWN)
    {
      while (*tmpy > *objy)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *tmpy -= 1;
	}
    }
}

void			Perso::go_left(int *tmpx, int *tmpy, int *objx)
{
  //std::cout << "On va a gauche !" << std::endl;
  if (this->_way == UP)
    {
      //std::cout << "A gauche !" << std::endl;
      this->_action.push_back("gauche\n");
      this->_way = LEFT;
      *tmpx -= 1;
      while (*tmpx > *objx)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *tmpx -= 1;
	}
    }
  else if (this->_way == DOWN)
    {
      //std::cout << "A droite !" << std::endl;
      this->_action.push_back("droite\n");
      this->_way = LEFT;
      *tmpx -= 1;
      while (*tmpx > *objx)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *tmpx -= 1;
	}
    }
  else if (this->_way == RIGHT)
    {
      /*std::cout << "A gauche !" << std::endl;
      std::cout << "A gauche !" << std::endl;
      std::cout << "A gauche !" << std::endl;*/
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
      this->_way = DOWN;
      *tmpx -= 1;
    }
  else if (this->_way == LEFT)
    {
      while (*tmpx > *objx)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *tmpx -= 1;
	}
    }
}

void			Perso::go_right(int *tmpx, int *tmpy, int *objx)
{
  //std::cout << "On va a droit !" << std::endl;
  if (this->_way == UP)
    {
      //std::cout << "A droite !" << std::endl;
      this->_action.push_back("droite\n");
      this->_way = RIGHT;
      *tmpx += 1;
      while (*tmpx < *objx)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *tmpx += 1;
	}
    }
  else if (this->_way == DOWN)
    {
      //std::cout << "A gauche !" << std::endl;
      this->_action.push_back("gauche\n");
      this->_way = LEFT;
      *tmpx += 1;
      while (*tmpx < *objx)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *tmpx += 1;
	}
    }
  else if (this->_way == LEFT)
    {
      /*std::cout << "A gauche !" << std::endl;
      std::cout << "A gauche !" << std::endl;
      std::cout << "A gauche !" << std::endl;*/
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
      this->_action.push_back("gauche\n");
      this->_way = UP;
      *tmpx += 1;
    }
  else if (this->_way == RIGHT)
    {
      while (*tmpx < *objx)
	{
	  //std::cout << "Devant !" << std::endl;
	  this->_action.push_back("avance\n");
	  *tmpx += 1;
	}
    }
}

void                    Perso::go_to_obj(int *coord_obj)
{
  bool                  find = false;
  int                   objx;
  int                   objy;
  int                   tmpx = this->_posx;
  int                   tmpy = this->_posy;

  //  std::cout << "x : " << this->_posx << " y : " << this->_posy;
  //std::cout << "Posx : " << this->_posx << " Posy : " << this->_posy;
  if (this->_way == UP)
    {
      objx = this->_posx + coord_obj[0];
      objy = this->_posy + coord_obj[1];
    }
  if (this->_way == DOWN)
    {
      objx = this->_posx - coord_obj[0];
      objy = this->_posy - coord_obj[1];
    }
  if (this->_way == LEFT)
    {
      objx = this->_posx - coord_obj[1];
      objy = this->_posy + coord_obj[0];
    }
  if (this->_way == RIGHT)
    {
      objx = this->_posx + coord_obj[0];
      objy = this->_posy - coord_obj[1];
    }
  while (find == false)
    {
      if (tmpx < objx) // obj a droite 
	this->go_right(&tmpx, &tmpy, &objx);
      else if (tmpx > objx) // obj a gauche
	this->go_left(&tmpx, &tmpy, &objx);
      else if (tmpy > objy) // obj en bas
	this->go_down(&tmpy, &tmpx, &objy);
      else if (tmpy < objy) // obj en haut
	this->go_up(&tmpy, &tmpx, &objy);
      if ((objx == tmpx) && (objy == tmpy))
	{
	  //std::cout << "Fini !" << std::endl;
	  find = true;
	}
    }
}
