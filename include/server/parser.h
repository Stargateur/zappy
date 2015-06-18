/*
** parser.h for parser in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jun 18 18:37:14 2015 Antoine Plaskowski
** Last update Thu Jun 18 23:51:59 2015 Antoine Plaskowski
*/

#ifndef		PARSER_H_
# define	PARSER_H_

struct		s_fct_parse
{
  char const	*cmd;
  void		*(*fct)(void);
};

#endif		/* !PARSER_H_ */
