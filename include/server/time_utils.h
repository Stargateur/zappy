/*
** time_utils.h for time_utils in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Jul  4 13:25:39 2015 Antoine Plaskowski
** Last update Sat Jul  4 15:32:44 2015 Antoine Plaskowski
*/

#ifndef		TIME_UTILS_H_
# define	TIME_UTILS_H_

# include	<stddef.h>
# include	<stdbool.h>
# include	<time.h>

# define	NANO_BY_SEC	(1000000000)

typedef	struct	timespec	t_time;

bool		time_add(t_time * const a, t_time const * const b);
bool		time_sub(t_time * const a, t_time const * const b);
bool		time_small(t_time const * const a, t_time const * const b);
bool		time_div(t_time * const a, size_t const num, size_t const den);
bool		time_show(t_time const * const a);

#endif		/* !TIME_UTILS_H_ */
