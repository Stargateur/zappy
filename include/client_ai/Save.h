/*
** Save.h for Save in /home/xila/unix/new_year/PSU_2014_zappy/source/client_ai
** 
** Made by amoure_a
** Login   <alix amoureux@epitech.net>
** 
** Started on  Fri Jun 19 19:01:23 2015 amoure_a
** Last update Fri Jun 19 19:31:37 2015 amoure_a
*/

#ifndef			SAVE_H
# define		SAVE_H

# include		<list>
# include		<iostream>
# include		"Mouv.h"

class			Save
{
 private:
  std::list<Mouv>	mouv;
  int			cpt;

 public:
  Save();
  ~Save();

 public:
  void		addItem(std::string action, int sens);
  void		removeItem();
  void		seeList();
};

#endif
