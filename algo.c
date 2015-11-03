/*
** algo.c for algo.c in /home/pras_m/rendu/cursus_dedie/Cartographer
** 
** Made by PRAS Martin
** Login   <pras_m@epitech.net>
** 
** Started on  Wed Oct 21 21:52:28 2015 PRAS Martin
** Last update Wed Oct 21 21:52:29 2015 PRAS Martin
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/cartographer.h"

int	*generate_maze(tab, size)
{
	int	exit_position;
	int	exit_orientation;
	
	exit_orientation = rand()%4;
	exit_position = rand()%size;
	tab = fill_tab(tab, size);
	check_tab(tab, size, exit_orientation, exit_position);
	print_tab(tab, size, exit_orientation, exit_position);
	return (0);
}

