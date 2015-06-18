/*
** cbuf.c for  in /home/zwertv_e/rendu/PSU_2014_myirc/source/server
** 
** Made by zwertv_e
** Login   <zwertv_e@epitech.net>
** 
** Started on  Thu Apr  9 19:39:37 2015 zwertv_e
** Last update Thu Jun 18 21:22:28 2015 Antoine Plaskowski
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"cbuf.h"

static size_t	add_one_cbuf_len(size_t const a)
{
  if (a + 1 >= CBUF_LEN)
    return (0);
  return (a + 1);
}

bool		set_cbuf(t_cbuf *cbuf)
{
  if (cbuf == NULL)
    return (true);
  cbuf->r = 0;
  cbuf->w = 0;
  cbuf->has_read = true;
  return (0);
}

static size_t	find_len(t_cbuf *cbuf)
{
  size_t	len;
  size_t	i;

  i = cbuf->r;
  len = 0;
  while (len < CBUF_LEN)
    {
      if (cbuf->buf[i] == '\0')
	return (0);
      if (cbuf->buf[i] == '\n')
	return (len);
      i = add_one_cbuf_len(i);
      len++;
    }
  return (0);
}

bool		is_cbuf_ready(t_cbuf *cbuf)
{
  if (cbuf == NULL)
    return (true);
  if (find_len(cbuf) == 0)
    return (true);
  return (false);
}

char		*read_cbuf(t_cbuf *cbuf)
{
  char		*str;
  size_t	len;
  size_t	i;

  if (cbuf == NULL)
    return (NULL);
  len = find_len(cbuf);
  if (len == 0 || (str = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < len)
    {
      str[i] = cbuf->buf[cbuf->r];
      cbuf->buf[cbuf->r] = '\0';
      cbuf->r = add_one_cbuf_len(cbuf->r);
      i++;
    }
  str[i] = '\0';
  cbuf->has_read = true;
  return (str);
}

ssize_t		write_cbuf(int fd, t_cbuf *cbuf)
{
  static char	buffer[CBUF_LEN];
  ssize_t	i;
  size_t	j;

  if ((i = read(fd, buffer, CBUF_LEN)) <= 0)
    return (i);
  if (cbuf->w == cbuf->r && cbuf->has_read == false)
    cbuf->r = add_one_cbuf_len(cbuf->r);
  j = 0;
  while (j < (size_t)i)
    {
      cbuf->buf[cbuf->w] = buffer[j];
      cbuf->w = add_one_cbuf_len(cbuf->w);
      if (cbuf->w == cbuf->r && j != (size_t)i)
	cbuf->r = add_one_cbuf_len(cbuf->r);
      j++;
    }
  cbuf->has_read = false;
  return (i);
}
