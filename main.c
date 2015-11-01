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
#include "include/struct.h"
#include "include/cartographer.h"

int	main(int ac, char **av)
{
	int size;
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
			if (!(carto = init_struct(carto, size)))
			{
				my_puterr("Failed to init struct\n");
		 		return (0);
		 	}
		 	my_put_nbr(carto->size);
			my_putstr("Welcome to Dedale's Amazing Maze\nGenerating a Maze of size ");
			my_put_nbr(size);
			my_putstr(" ...\n");
			
			if (!(carto = generate_maze(carto)))
			{
				my_puterr("Failed to generate maze\n");
		 		return (0);
			}
		}
	}
	else 
	{
		my_puterr("Usage: ./dedale size(9-29)\n");
		return (0);
	}

	  return (0);
}



t_carto	*init_struct(t_carto *carto, int size)
{
  if (!(carto = malloc(sizeof(t_carto *))))
    return (NULL);
  carto->size = size;
  carto->exit_orientation = rand() % 4;
  carto->exit_position = rand() % size;
  carto->center = size / 2 + 1;
  if (!(carto = malloc_tab(carto)))
    return (NULL);
  if (!(carto = fill_tab(carto)))
    return (NULL);
  return (carto);
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
