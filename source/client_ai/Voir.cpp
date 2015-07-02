#include		"Perso.hpp"

void                    Perso::put_objects_in_case(int x, int y, std::string answer)
{
  int                   i = 0;
  int                   nb_objects =  std::count(answer.begin(), answer.end(), ' ');

  this->_sav->map[this->_posy][this->_posx].push_back(PLAYER);

  // ne gère pas le fait s'il y a plusieurs fois le même objet dans la case !          
  while (i < nb_objects)
    {
      if (strstr(answer.c_str(), "joueur") != NULL)
        this->_sav->map[y][x].push_back(PLAYER);
      else if (strstr(answer.c_str(), "linemate") != NULL)
        this->_sav->map[y][x].push_back(LINEMATE);
      else if (strstr(answer.c_str(), "deraumere") != NULL)
        this->_sav->map[y][x].push_back(DERAUMERE);
      else if (strstr(answer.c_str(), "sibur") != NULL)
        this->_sav->map[y][x].push_back(SIBUR);
      else if (strstr(answer.c_str(), "mendiane") != NULL)
        this->_sav->map[y][x].push_back(MENDIANE);
      else if (strstr(answer.c_str(), "phiras") != NULL)
        this->_sav->map[y][x].push_back(PHIRAS);
      else if (strstr(answer.c_str(), "thystame") != NULL)
        this->_sav->map[y][x].push_back(THYSTAME);
      else if (strstr(answer.c_str(), "nourriture") != NULL)
        this->_sav->map[y][x].push_back(FOOD);
      i++;
    }
}

void                    Perso::save_objects_in_map(std::string objects, int i)
{
  int                   line = 1;
  int                   column = 0;
  int                   tmpcol = 0;
  int                   tmpline = 0;
  int                   cpt = 0;
  int                   cur_num_col = 0;
  int                   cur_num_line = 0;
  int                   diff = 0;
  int                   coef_vert = 0;
  int                   coef_hor = 0;

  std::cout << "posx : " << this->_posx << " posy : " << this->_posy << std::endl;
  // map non circulaire
  if (this->_way == UP || this->_way == DOWN)
    {
      if (this->_way == UP)
        coef_vert = -1;
      if (this->_way == DOWN)
        coef_vert = 1;
      while (line <= (this->_level + 1))
        {
	  std::cout << line << std::endl;
          cur_num_line = this->_posy + (line * coef_vert);
          tmpcol = 0;
          while (tmpcol <= (column))
            {
              if (cpt == i)
                {
                  if (tmpcol < (column / 2))
                    {
                      diff = (column / 2) - tmpcol;
                      if (diff < 0)
                        diff = -diff;
                      if (this->_way == UP)
                        cur_num_col = this->_posx - diff;
                      if (this->_way == DOWN)
                        cur_num_col = this->_posx + diff;
                    }
                  else if (tmpcol > (column / 2))
                    {
                      diff = (column / 2) - tmpcol;
                      if (diff < 0)
                        diff = -diff;
                      if (this->_way == UP)
                        cur_num_col = this->_posx + diff;
                      if (this->_way == DOWN)
                        cur_num_col = this->_posx - diff;
                    }
                  else
                    cur_num_col = this->_posx;
                  this->put_objects_in_case(cur_num_col, cur_num_line, objects);
                }
              cpt++;
              tmpcol++;
            }
          column += 2;
          line++;
        }
    }
  line = 0;
  column = 1;
  cpt = 0;
  if (this->_way == LEFT || this->_way == RIGHT)
    {
      if (this->_way == LEFT)
        coef_hor = -1;
      if (this->_way == RIGHT)
        coef_hor = 1;
      while (column <= (this->_level + 1))
        {
          cur_num_col = this->_posx + (column * coef_hor);
	  tmpline = 0;
          while (tmpline <= line)
            {
              if (cpt == i)
                {
                  if (tmpline < (line / 2))
                    {
                      diff = (line / 2) - tmpline;
                      if (diff < 0)
                        diff = -diff;
                      if (this->_way == LEFT)
                        cur_num_line = this->_posy + diff;
                      if (this->_way == RIGHT)
                        cur_num_line = this->_posy - diff;
                    }
                  else if (tmpline > (line / 2))
                    {
                      diff = (line / 2) - tmpline;
                      if (diff < 0)
                        diff = -diff;
                      if (this->_way == LEFT)
                        cur_num_line = this->_posy - diff;
                      if (this->_way == RIGHT)
                        cur_num_line = this->_posy + diff;
                    }
                  else
		      cur_num_line = this->_posy;
		  std::cout << "x : " << cur_num_line << " y : " << cur_num_col << std::endl;
                  this->put_objects_in_case(cur_num_col, cur_num_line, objects);
		}
              cpt++;
              tmpline++;
	    }
	  line += 2;
          column++;
        }
    }
}

void                    Perso::voir(std::string answer)
{
  int                   i = 0;
  int                   nb_cases;
  int                   pos_first_coma;
  int                   pos_second_coma;
  std::string           objects_by_case;

  this->_time += 7;
  this->_sav->mouv.push_back("voir");
  ndl;                                                                                   
  nb_cases = std::count(answer.begin(), answer.end(), ',');
  pos_first_coma = answer.find_first_of("{") + 1;
  while (i < nb_cases)
    {
      pos_second_coma = answer.find_first_of(",");
      objects_by_case = answer.substr(pos_first_coma, pos_second_coma - pos_first_coma\
				      );
      this->save_objects_in_map(objects_by_case, i);
      answer = answer.replace(pos_second_coma, 1, "");
      pos_first_coma = pos_second_coma;
      i++;
    }
  pos_second_coma = answer.find_first_of("}");
  objects_by_case = answer.substr(pos_first_coma, pos_second_coma - pos_first_coma);
  this->save_objects_in_map(objects_by_case, i);
  this->see_map();
  this->_sav->cpt++;
}
