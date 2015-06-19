/*
** Mouv.h for Mouv in /home/xila/unix/new_year/PSU_2014_zappy/source/client_ai
** 
** Made by amoure_a
** Login   <alix amoureux@epitech.net>
** 
** Started on  Fri Jun 19 19:05:33 2015 amoure_a
** Last update Fri Jun 19 19:42:11 2015 amoure_a
*/

#ifndef			MOUV_H
# define		MOUV_H

# include		<string>
# include		<string>

class			Mouv
{
 public:
  typedef enum		s_sens
  {
    LEFT = 0,
    RIGHT = 1,
    UP = 2,
    DOWN = 3
  }			t_sens;
 private:
  std::string		action;
  t_sens		sens;

 public:
  Mouv(std::string action, int sens);
  ~Mouv();

  std::string		getAction() const;
  int			getSens() const;
};

#endif
