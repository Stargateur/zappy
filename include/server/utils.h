/*
** utils.h for utils in /home/plasko_a/projet/epitech/PSU_2014_zappy
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Jun 29 15:40:05 2015 Antoine Plaskowski
** Last update Sun Jul  5 03:48:01 2015 Antoine Plaskowski
*/

#ifndef		UTILS_H_
# define	UTILS_H_

# include	<stddef.h>
# include	<stdbool.h>

size_t		len_tab(void * const * const tab);
bool		write_fd(char const * const str, int const fd);
char		*malloc_vsnprintf(char *format, ...);

#endif		/* !UTILS_H_ */
