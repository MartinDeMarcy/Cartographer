/*
** print.c for print.c in /home/pras_m/rendu/cursus_dedie/Cartographer
** 
** Made by PRAS Martin
** Login   <pras_m@epitech.net>
** 
** Started on  Mon Nov  2 20:18:26 2015 PRAS Martin
** Last update Mon Nov  2 20:18:28 2015 PRAS Martin
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/cartographer.h"

void	print_north(int size, int exit_orientation, int exit_position)
{
	int	i;
	int	x;
	
	i = 0;
	x = 0;
	my_putchar('X');
	while (i < size)
	 {
		if ((exit_orientation == 0) && (exit_position == i))
		{
			my_putchar(32);
		}
		else {
			my_putchar('X');
		}
		i++;
	 }
	my_putstr("X\n");
}

void	print_south(int size, int exit_orientation, int exit_position)
{
	int	i;
	int	x;
	
	i = 0;
	x = 0;
	my_putchar('X');
	while (i < size)
	 {
		if ((exit_orientation == 2) && (exit_position == i))
		{
			my_putchar(32);
		}
		else {
			my_putchar('X');
		}
		i++;
	 }
	my_putstr("X\n");
}

void	print_tab(char ** tab, int size)
{
	int	i;
	int	exit_position;
	int	exit_orientation;

	i = 0;
	exit_orientation = rand()%4;
	exit_position = rand()%size;
	print_north(size, exit_orientation, exit_position);
	while (i < size)
	 {
	 	if ((exit_orientation == 3) && (exit_position == i))
	 	{
	 		my_putchar(32);
	 	}
	 	else
	 	{
			my_putchar('X');
		}
		my_putstr(tab[i]);
		if ((exit_orientation == 1) && (exit_position == i))
	 	{
	 		my_putchar(32);
	 	}
	 	else
	 	{
			my_putchar('X');
		}
		my_putchar('\n');
		i++;
	 }
	print_south(size, exit_orientation, exit_position);
	my_putchar('\n');
}
