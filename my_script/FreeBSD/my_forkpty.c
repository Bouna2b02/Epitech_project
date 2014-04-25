/*
** my_forkpty.c for forkpty in /home/corbac_b/My Dropbox/epitech/C/my_script/FreeBSD
** 
** Made by anthony1 corbacho
** Login   <corbac_b@epitech.net>
** 
** Started on  Tue Feb  9 18:22:44 2010 anthony1 corbacho
** Last update Thu Feb 11 00:09:23 2010 anthony1 corbacho
*/

#include		"header_script.h"

int			erro_pty(int code)
{
  char			*str;

  if (code == 1)
    str = "Openpty fail\n";
  if (code == 2)
    str = "Fork on forkpty fail\n";
  if (code == 3)
    str = "Login_ttp on forkpty fail\n";
  write(2, str, my_strlen(str));
  return (-1);
}

pid_t			my_forkpty(int *amaster, char *name,
				   t_termios *term,
				   t_winsize *winp)
{
  pid_t			pid;
  int			aslave;

  if (my_openpty(amaster, &aslave, name, term, winp) == -1)
    return (erro_pty(1));
  if ((pid = fork()) == -1)
    return (erro_pty(2));
  if (pid == 0)
    {
      close(*amaster);
      if (my_login_tty(aslave) == -1)
	return (erro_pty(3));
      return (0);
    }
  else
    {
      close(aslave);
      return (pid);
    }
}
