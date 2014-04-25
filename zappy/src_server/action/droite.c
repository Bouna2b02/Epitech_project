/*
** droite.c for zappy in /home/damien/work_local/my_zappy/src_server/action
** 
** Made by damien1 coppel
** Login   <coppel_a@epitech.net>
** 
** Started on  Sun Mar 21 17:49:13 2010 damien1 coppel
** Last update Tue Apr 20 10:21:40 2010 damien1 coppel
*/

#include <stdlib.h>

#include "lstr.h"
#include "lxsys.h"

#include "action.h"
#include "action_gr.h"
#include "map.h"
#include "message.h"

char		*droite(t_client *cl, __attribute__((unused)) t_request *req)
{
  if (cl->orientation == 3)
    cl->orientation = 0;
  else
    ++cl->orientation;
  send_to_graph(player_pos_gr(cl));
  return (my_strdup(OK));
}
