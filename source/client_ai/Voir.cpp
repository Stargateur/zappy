#include		"Perso.hpp"

void                    Perso::put_objects_in_case(int x, int y, std::string answer)
{
  int                   i = 0;
  int                   nb_objects =  std::count(answer.begin(), answer.end(), ' ');
  size_t		pos;

  this->_sav->map[y][x].clear();
  //this->_sav->map[this->_posy][this->_posx].push_back(PLAYER);
  while (i < nb_objects)
    {
      if (strstr(answer.c_str(), "joueur") != NULL)
	{
	  pos = answer.find_first_of("joueur");
	  answer = answer.replace(pos, pos + 6, "");
	  this->_sav->map[y][x].push_back(PLAYER);
	  this->_sav->map[y][x].remove(NONE);
	}
      else if (strstr(answer.c_str(), "linemate") != NULL)
	{
	  pos = answer.find_first_of("linemate");
	  answer = answer.replace(pos, pos + 8, "");
	  this->_sav->map[y][x].push_back(LINEMATE);
	  this->_sav->map[y][x].remove(NONE);
	}
      else if (strstr(answer.c_str(), "deraumere") != NULL)
	{
	  pos = answer.find_first_of("deraumere");
	  answer = answer.replace(pos, pos + 9, "");
	  this->_sav->map[y][x].push_back(DERAUMERE);
	  this->_sav->map[y][x].remove(NONE);
	}
      else if (strstr(answer.c_str(), "sibur") != NULL)
	{
	  pos = answer.find_first_of("sibur");
	  answer = answer.replace(pos, pos + 5, "");
	  this->_sav->map[y][x].push_back(SIBUR);
	  this->_sav->map[y][x].remove(NONE);
	}
      else if (strstr(answer.c_str(), "mendiane") != NULL)
	{
	  pos = answer.find_first_of("mendiane");
	  answer = answer.replace(pos, pos + 8, "");
	  this->_sav->map[y][x].push_back(MENDIANE);
	  this->_sav->map[y][x].remove(NONE);
	}
      else if (strstr(answer.c_str(), "phiras") != NULL)
	{
	  pos = answer.find_first_of("phiras");
	  answer = answer.replace(pos, pos + 6, "");
	  this->_sav->map[y][x].push_back(PHIRAS);
	  this->_sav->map[y][x].remove(NONE);
	}
      else if (strstr(answer.c_str(), "thystame") != NULL)
	{
	  pos = answer.find_first_of("thystame");
	  answer = answer.replace(pos, pos + 8, "");
	  this->_sav->map[y][x].push_back(THYSTAME);
	  this->_sav->map[y][x].remove(NONE);
	}
      else if (strstr(answer.c_str(), "nourriture") != NULL)
	{
	  pos = answer.find_first_of("nourriture");
	  answer = answer.replace(pos, pos + 10, "");
	  this->_sav->map[y][x].push_back(FOOD);
	  this->_sav->map[y][x].remove(NONE);
	}
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

  // map non circulaire
  if (this->_way == UP || this->_way == DOWN)
    {
      if (this->_way == UP)
        coef_vert = -1;
      if (this->_way == DOWN)
        coef_vert = 1;
      while (line <= (this->_level + 1))
        {
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

		  if (cur_num_col > (this->_maplength - 1))
		    cur_num_col = cur_num_col - this->_maplength;
		  if (cur_num_col < 0)
		    cur_num_col = this->_maplength + cur_num_col;
		  if (cur_num_line > (this->_mapheight - 1))
		    cur_num_line = cur_num_line - this->_mapheight;
		  if (cur_num_line < 0)
		    cur_num_line = this->_mapheight + cur_num_line;

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

		  if (cur_num_col > (this->_maplength - 1))
		    cur_num_col = cur_num_col - this->_maplength;
		  if (cur_num_col < 0)
		    cur_num_col = this->_maplength + cur_num_col;
		  if (cur_num_line > (this->_mapheight - 1))
		    cur_num_line = cur_num_line - this->_mapheight;
		  if (cur_num_line < 0)
		    cur_num_line = this->_mapheight + cur_num_line;

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
