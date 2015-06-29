/*
** parser.h for parser in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jun 18 18:37:14 2015 Antoine Plaskowski
** Last update Mon Jun 29 19:24:40 2015 Antoine Plaskowski
*/

#ifndef		PARSER_H_
# define	PARSER_H_

# include	<stddef.h>

typedef	struct	s_cmd	t_cmd;
struct		s_cmd
{
  char const	*cmd;
  void		*(*fct)(void);
  size_t	time;
};

#endif		/* !PARSER_H_ */
