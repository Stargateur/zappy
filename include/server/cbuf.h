/*
** cbuf.h for cbuf in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jun 18 21:18:19 2015 Antoine Plaskowski
** Last update Thu Jun 25 21:55:06 2015 Antoine Plaskowski
*/

#ifndef		CBUF_H_
# define	CBUF_H_

# include	<stdbool.h>

# define	CBUF_LEN	4096

typedef	struct	s_cbuf	t_cbuf;

struct		s_cbuf
{
  char		buf[CBUF_LEN];
  size_t	r;
  size_t	w;
  bool		has_read;
};

t_cbuf		*init_cbuf(t_cbuf * const cbuf);
bool		is_cbuf_ready(t_cbuf const * const cbuf);
char		*read_cbuf(t_cbuf * const cbuf);
ssize_t		write_cbuf(t_cbuf * const cbuf, int const fd);

#endif		/* !CBUF_H_ */
