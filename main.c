/*
** main.c for main.c in /home/pras_m/rendu/cursus_dedie/Cartographer
** 
** Made by PRAS Martin
** Login   <pras_m@epitech.net>
** 
** Started on  Wed Oct 21 19:28:33 2015 PRAS Martin
** Last update Wed Oct 21 19:29:12 2015 PRAS Martin
*/

#include <stdlib.h>
#include <time.h>
#include "include/cartographer.h"

int	main(int ac, char **av)
{
	int size;
	char	**tab;
	t_carto	*carto;
	
	srand (time(NULL));
	if (ac == 2)
	{
		size = checker(av[1]);
		if (size == 1)
		{
			my_puterr("Invalid arguments: Only odd number between 9 and 29 inclued are allowed\n");
			return (0);
		}
		else
		{
		 	tab = malloc_tab(tab, size);
			my_putstr("Welcome to Dedale's Amazing Maze\nGenerating a Maze of size ");
			my_put_nbr(size);
			my_putstr(" ...\n");
			generate_maze(tab, size);
		}
	}
	else 
	{
		my_puterr("Usage: ./dedale size(9-29)\n");
		return (0);
	}
	free(carto);
	  return (0);
}

int	checker(char *str)
{
	int	i;
	int	size;
	int	tmp;
	
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 48) && (str[i] <= 57))
		{ 
			i++;
		}
		else
		{
			return (1);
		}
	}
	if (is_odd(str) == 1)
	{
		return (1);
	}
	size = my_getnbr(str);
	return (size);
}

int	is_odd(char *str)
{
	int i;
	int length;
	
	length = my_strlen(str) - 1;
	i = 0;
	if ((str[length] == 48) || (str[length] == 50) || (str[length] == 52))
	{
		return (1);
	}
	else if ((str[length] == 54)  || (str[length] == 56))
	{
		return (1);
	}
	return (0);
}
