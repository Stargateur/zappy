/*
** fd_set.h for fd_set in /home/plasko_a/projet/epitech/PSU_2014_myirc
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Mar 25 15:51:29 2015 Antoine Plaskowski
** Last update Thu Jun 18 16:49:20 2015 Antoine Plaskowski
*/

#ifndef		FD_SET_H_
# define	FD_SET_H_

# include	<stdbool.h>
# include	<sys/select.h>

int		fd_set_cpy(fd_set * const dest, fd_set const * const cpy);
int		fd_set_close(fd_set const * const fd_set);

#endif		/* !FD_SET_H_ */
