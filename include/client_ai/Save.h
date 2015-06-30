/*
** Save.h for Save in /home/xila/unix/new_year/PSU_2014_zappy/source/client_ai
** 
** Made by amoure_a
** Login   <alix amoureux@epitech.net>
** 
** Started on  Fri Jun 19 19:01:23 2015 amoure_a
** Last update Tue Jun 30 16:12:46 2015 Jérémy MATHON
*/

#ifndef			SAVE_H
# define		SAVE_H

# include		<list>
# include		<iostream>
# include		<string>
# include		<vector>
# include		"Mouv.h"

typedef enum		s_case
  {
    LINEMATE = 0,
    DERAUMERE = 1,
    SIBUR = 2,
    MENDIANE = 3,
    PHIRAS = 4,
    THYSTAME = 5,
    PLAYER = 6,
    NONE = 7
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

 public:
  // void		addItem(std::string action, int sens);
  // void		removeItem();
  // void		seeList();
};

#endif
