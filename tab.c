/*
** tab.c for tab.c in /home/pras_m/rendu/cursus_dedie/Cartographer
** 
** Made by PRAS Martin
** Login   <pras_m@epitech.net>
** 
** Started on  Tue Nov  3 19:05:13 2015 PRAS Martin
** Last update Tue Nov  3 19:05:15 2015 PRAS Martin
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/cartographer.h"

char	**malloc_tab(char **tab, int size)
{
  int	i;

  i = 0;
  if (!(tab = malloc((sizeof(char *) * size) * size)))
    return (NULL);
  while (i < size)
    {
      if (!(tab[i] = malloc(sizeof(char) * size)))
	return (NULL);
      i++;
    }
  return (tab);
}

char	**fill_tab(char **tab, int size, int seed)
{
	int	random;
	int	i;
	int	j;
	int	center;
	char	*legit_char;
	

	legit_char = "XXXXXXXXX           ";
	i = 0;
	random = my_random(seed);
	center = size / 2;
	while (i < size)
	 {
		j = 0;
		while (j < size)
		{
			random = my_random(random);
		  tab[i][j] = legit_char[random%20];
		  if (j == center)
		  	if (i == center)
		  		tab[i][j] = 32;
		  j++;
		}
		i++;
	 }
	return (tab);
}
