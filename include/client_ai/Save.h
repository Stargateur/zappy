/*
** Save.h for Save in /home/xila/unix/new_year/PSU_2014_zappy/source/client_ai
** 
** Made by amoure_a
** Login   <alix amoureux@epitech.net>
** 
** Started on  Fri Jun 19 19:01:23 2015 amoure_a
** Last update Sun Jul  5 03:46:54 2015 Antoine Plaskowski
*/

#ifndef			SAVE_H_
# define		SAVE_H_

# include		<list>
# include		<iostream>
# include		<string>
# include		<vector>

typedef enum		s_case
  {
    LINEMATE = 0,
    DERAUMERE = 1,
    SIBUR = 2,
    MENDIANE = 3,
    PHIRAS = 4,
    THYSTAME = 5,
    PLAYER = 6,
    FOOD = 7,
    NONE = 8
  }			t_case;

class			Save
{
 public:
  std::list<std::string>				mouv;
  int							cpt;
  std::vector<std::vector<std::list <t_case> > >	map;
 public:
  Save();
  ~Save();
};

#endif
