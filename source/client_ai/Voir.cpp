//
// Voir.cpp for Voir in /home/xila/PSU_2014_zappy
// 
// Made by amoure_a
// Login   <alix amoureux@epitech.net>
// 
// Started on  Sun Jul  5 22:50:36 2015 amoure_a
// Last update Sun Jul  5 22:50:37 2015 amoure_a
//

#include		"Perso.hpp"

int			Perso::count_obj_by_case(const std::string &str, const std::string sub)
{
  int			count = 0;

  if (sub.length() == 0)
    return (0);
  for (size_t offset = str.find(sub); offset != std::string::npos; offset = str.find(sub, offset + sub.length()))
    count++;
  return (count);
}

void                    Perso::put_objects_in_case(const int& x, const int& y, const std::string &tmp, const int& i)
{
  int		       f = count_obj_by_case(tmp, "nourriture");
  int		       l = count_obj_by_case(tmp, "linemate");
  int		       s = count_obj_by_case(tmp, "sibur");
  int		       m = count_obj_by_case(tmp, "mendiane");
  int		       p = count_obj_by_case(tmp, "phiras");
  int		       t = count_obj_by_case(tmp, "thystame");
  int		       j = count_obj_by_case(tmp, "joueur");
  int		       d = count_obj_by_case(tmp, "deraumere");

  this->_sav->map[y][x].clear();
  if (f == 0 && l == 0 && s == 0 && m == 0 && p == 0 && t == 0 && j == 0 && d == 0)
    this->_sav->map[y][x].push_back(NONE);
  else
    {
      if (i == 0)
	j--;
      while (f > 0)
	{
	  this->_sav->map[y][x].push_back(FOOD);
	  f--;
	}
      while (l > 0)
	{
	  this->_sav->map[y][x].push_back(LINEMATE);
	  l--;
	}
      while (s > 0)
	{
	  this->_sav->map[y][x].push_back(SIBUR);
	  s--;
	}
      while (m > 0)
	{
	  this->_sav->map[y][x].push_back(MENDIANE);
	  m--;
	}
      while (p > 0)
	{
	  this->_sav->map[y][x].push_back(PHIRAS);
	  p--;
	}
      while (t > 0)
	{
	  this->_sav->map[y][x].push_back(THYSTAME);
	  t--;
	}
      while (j > 0)
	{   
	  this->_sav->map[y][x].push_back(PLAYER);
	  j--;
	}
      while (d > 0)
	{
	  this->_sav->map[y][x].push_back(DERAUMERE);
	  d--;
	}
    }
}
  
void                    Perso::save_objects_in_map(const std::string &objects, const int& i)
{
  int                   line = 0;
  int                   column = 0;
  int                   tmpcol = 0;
  int                   tmpline = 0;
  int                   cpt = 0;
  int                   cur_num_col = 0;
  int                   cur_num_line = 0;
  int                   diff = 0;
  int                   coef_vert = 0;
  int                   coef_hor = 0;

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
		  this->put_objects_in_case(cur_num_col, cur_num_line, objects, i);
		}
	      cpt++;
	      tmpcol++;
	    }
	  column += 2;
	  line++;
	}
    }
  line = 0;
  column = 0;
  cpt = 0;
  if (this->_way == LEFT || this->_way == RIGHT)
    {
      if (this->_way == LEFT)
	coef_hor = -1;
      if (this->_way == RIGHT)
	coef_hor = 1;
      while (column <= (this->_level))
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

		  this->put_objects_in_case(cur_num_col, cur_num_line, objects, i);
		}
	      cpt++;
	      tmpline++;
	    }
	  line += 2;
	  column++;
	}
    }
}

void                    Perso::voir(std::string& answer)
{
  int                   i = 0;
  int                   nb_cases;
  int                   pos_first_coma;
  int                   pos_second_coma;
  std::string           objects_by_case;

  this->_time += 7;
  this->_sav->mouv.push_back("voir\n");
  nb_cases = std::count(answer.begin(), answer.end(), ',');
  pos_first_coma = answer.find_first_of("{") + 1;
  while (i < nb_cases)
    {
      pos_second_coma = answer.find_first_of(",");
      objects_by_case = answer.substr(pos_first_coma, pos_second_coma - pos_first_coma);
      this->save_objects_in_map(objects_by_case, i);
      answer = answer.replace(pos_second_coma, 1, "");
      pos_first_coma = pos_second_coma;
      i++;
    }
  pos_second_coma = answer.find_first_of("}");
  objects_by_case = answer.substr(pos_first_coma, pos_second_coma - pos_first_coma);
  this->save_objects_in_map(objects_by_case, i);
  this->_sav->cpt++;
}
