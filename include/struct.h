/*
** struct.h for struct.h in /home/pras_m/rendu/cursus_dedie/Cartographer
** 
** Made by PRAS Martin
** Login   <pras_m@epitech.net>
** 
** Started on  Fri Oct 30 21:40:20 2015 PRAS Martin
** Last update Fri Oct 30 21:41:17 2015 PRAS Martin
*/

#ifndef STRUCT_H_
# define STRUCT_H

typedef struct s_carto
{
  int		size;
  char		**tab;
  int		exit_orientation;
  int		exit_position;
  int		center;
}		t_carto;

#endif