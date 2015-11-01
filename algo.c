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
#include "include/struct.h"
#include "include/cartographer.h"

t_carto	*generate_maze(t_carto *carto)
{
my_put_nbr(carto->exit_position);exit(0);
	print_tab(carto);
	



return (carto);
}

t_carto	*malloc_tab(t_carto *carto)
{
	int	i;
	
	i = 0;
	if (!(carto->tab = malloc((sizeof(char *) * carto->size) * carto->size)))
	 return (NULL);
	while (i < carto->size)
	 {
		if (!(carto->tab[i] = malloc(sizeof(char) * carto->size)))
	return (NULL);
		i++;
	 }
	return (carto);
}

t_carto	*fill_tab(t_carto *carto)
{
	int	random;
	int	i;
	int	j;
	char	*legit_char;
	
	legit_char = "X ";
	i = 0;
	while (i < carto->size)
	 {
		j = 0;
		while (j < carto->size)
	{
	  random = rand();
	  carto->tab[i][j] = legit_char[random%2];
//		my_put_nbr(random);exit(0);
	  j++;
	}
		i++;
	 }
	return (carto);
}

void	print_line(t_carto *carto)
{
	int	i;
	int	x;
	
	i = 0;
	x = 0;
	my_putchar('X');
	if ((carto->exit_orientation == 1) || (carto->exit_orientation == 4))
	{
		x = carto->exit_position;
	}
	while (i < carto->size)
	 {
	 if ((x != 0) && (x == i))
	 {
	 	my_putchar(32);
	 	x = 0;
	 }
		my_putchar('X');
		i++;
	 }
	my_putstr("X\n");
}

void	print_tab(t_carto *carto)
{
	int	i;

	i = 0;
	print_line(carto);
	while (i < carto->size)
	 {
		my_putchar('X');
		my_putstr(carto->tab[i]);
		my_putchar('X');
		my_putchar('\n');
		i++;
	 }
	print_line(carto);
	my_putchar('\n');
}
