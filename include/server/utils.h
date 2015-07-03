/*
** utils.h for utils in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Jun 29 15:40:05 2015 Antoine Plaskowski
** Last update Fri Jul  3 20:52:22 2015 Antoine Plaskowski
*/

#ifndef		UTILS_H_
# define	UTILS_H_

# include	<stddef.h>
# include	<stdbool.h>
# include	<time.h>

# define	NANO_BY_SEC	(1000000000)

typedef	struct	timespec	t_time;

size_t		len_tab(void * const * const tab);
bool		write_fd(char const * const str, int const fd);
bool		time_sub(t_time * const a, t_time const * const b);
bool		time_small(t_time const * const a, t_time const * const b);
bool		time_div(t_time * const a, size_t const num, size_t const den);

#endif		/* !UTILS_H_ */
