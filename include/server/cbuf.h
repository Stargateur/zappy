/*
** cbuf.h for cbuf in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jun 18 21:18:19 2015 Antoine Plaskowski
** Last update Thu Jun 18 21:20:41 2015 Antoine Plaskowski
*/

#ifndef		CBUF_H_
# define	CBUF_H_

# include	<stdbool.h>

# define	CBUF_LEN	512

typedef	struct	s_cbuf	t_cbuf;

struct		s_cbuf
{
  char		buf[CBUF_LEN];
  size_t	r;
  size_t	w;
  bool		has_read;
};

#endif		/* !CBUF_H_ */
