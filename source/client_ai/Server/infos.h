/*
** infos.h for infos in /home/alix/unix/new_year/myftp/test
** 
** Made by amoure_a
** Login   <alix amoureux@epitech.net>
** 
** Started on  Mon Mar  9 14:50:14 2015 amoure_a
** Last update Mon Jun 15 12:54:37 2015 amoure_a
*/

#ifndef		INFOS_H
# define	INFOS_H

# include	<iostream>
# include	<stdio.h>
# include	<stdlib.h>
# include	<sys/types.h>
# include	<sys/socket.h>
# include	<dirent.h>
# include	<netinet/in.h>
# include	<arpa/inet.h>
# include	<netdb.h>
# include	<string.h>
# include	<unistd.h>
# include	<signal.h>
# include	<stdbool.h>

typedef	 struct	s_infos
{
  char		*pathServer;
  char		*limitPathServer;
  char		*pathClient;
  char		*user;
  char		*tmp_ip;
  char		*tmp_port;
  int		port;
}		t_infos;

extern bool	g_endClient;

int		error_message(char *str, int cs);
char		*error_message_2(char *str, int cs);
int		get_file(char *, t_infos *, int cs);
int		put_file(char *, t_infos *, int cs);
void		read_file(FILE *fd, FILE *create_file, int cs);
int		execute_cd(char *buffer, t_infos *, int cs);
int		execute_pwd(int cs);
int		execute_ls(char *pathServer, int cs, t_infos *);
void		display_tab(char **tab, int cs);
int		catch_sig(int *, int);
int		init(int port);
int		add_socket(int port);
t_infos		*fill_struct();
void		execute_user(char *, t_infos *, int);
ssize_t		xwrite(int, void *, size_t);
ssize_t		xread(int, void *, size_t);
char		*xmalloc_char(int);
char		*xgetcwd();
char		*xstrcat(char *, char *);
char		*xstrdup(char *);
char		*xstrcpy(char *, char *);
void		add_fields(char *, t_infos *, int cs);

#endif
