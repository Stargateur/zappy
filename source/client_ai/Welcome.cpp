
#include	"Perso.hpp"

const void      *Perso::getTeamName()
{
  std::string   team_name;

  team_name = this->getTeam() + "\n";
  return ((const void *)team_name.c_str());
}

void            Perso::size_map_pos_ia(std::string coords)
{
  std::string   x;
  std::string   y;
  int           i;
  int           j;

  i = 0;
  x = coords.substr(0, coords.find_first_of(" "));
  y = coords.substr(coords.find_first_of(" ") + 1, coords.length());
  this->_mapheight = atoi(y.c_str());
  this->_maplength = atoi(x.c_str());
  //this->_posx = this->_maplength / 2;
  //this->_posy = this->_mapheight / 2;
  this->_posx = 5;
  this->_posy = 0;
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


void    Perso::welcome()
{
  ssize_t       res;
  std::string   welcome;
  std::string   num_client;
  std::string   coords;

  welcome.resize(100);
  res = read(this->getClient(), (void *)welcome.c_str(), 100);
  if (res != -1)
    {
      std::cout << welcome;
      res = write(this->getClient(), this->getTeamName(), (size_t)this->getTeam().size\
		  () + 1);
      if (res != -1)
        {
          num_client.resize(20);
          res = read(this->getClient(), (void *)num_client.c_str(), 20);
          if (res != -1)
            {
              this->_numclient = atoi(num_client.c_str());
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
