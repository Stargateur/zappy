/*
** circurlar_buffer.h for circurlar_buffer in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Jun 18 21:18:19 2015 Antoine Plaskowski
** Last update Wed Jul  1 06:17:48 2015 Antoine Plaskowski
*/

#ifndef		CIRCURLAR_BUFFER_H_
# define	CIRCURLAR_BUFFER_H_

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
bool		ready_cbuf(t_cbuf const * const cbuf);
char		*read_cbuf(t_cbuf * const cbuf);
ssize_t		write_cbuf(t_cbuf * const cbuf, int const fd);

#endif		/* !CIRCURLAR_BUFFER_H_ */
