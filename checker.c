/*
** checker.c for checker.c in /home/pras_m/rendu/cursus_dedie/Cartographer
** 
** Made by PRAS Martin
** Login   <pras_m@epitech.net>
** 
** Started on  Tue Nov  3 20:02:54 2015 PRAS Martin
** Last update Tue Nov  3 20:02:56 2015 PRAS Martin
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/cartographer.h"

char	**check_tab(char **tab, int size, int exit_orientation, int exit_position)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < size)
	 {
		j = 0;
		while (j < size)
		{
			tab = check_one(tab, i, j, (size - 1));
		  j++;
		}
		i++;
	 }
	 tab = check_exit(tab, exit_orientation, exit_position, (size -1));
	return (tab);
}

char	**check_one(char **tab, int i, int j, int size)
{
	if (tab[i][j] == 'X' && (size < 15))
		return (tab);
	if (i == 0)
	{
		if (j == 0)
		{
			if ((tab[i + 1][j] == 'X') && (tab[i][j + 1] == 'X')) /* Pour la case en haut a gauche quand i = 0 et j = 0 */
				{
					tab[i + 1][j] = ' ';
					tab[i][j + 1] = ' ';
					return (tab);
				}
		}
		else if (j == size)
		{
			if ((tab[i + 1][j] == 'X') && (tab[i][j - 1] == 'X')) /* Pour la case en haut a droite quand i = 0 et j = 27 */
				{
					tab[i + 1][j] = ' ';
					tab[i][j - 1] = ' ';
					return (tab);
				}
		}
		else
		{
			if ((tab[i][j + 1] == 'X') && (tab[i][j + 1] == 'X') && (tab[i][j - 1] == 'X')) /* Pour la premiere ligne quand i = 0*/
			{
				tab[i][j - 1] = ' ';
				tab[i + 1][j] = ' ';
				return (tab);
			}
		}
	}
	
	else if (i == size)
	{
		if (j == 0)
		{
			if ((tab[i - 1][j] == 'X') && (tab[i][j + 1] == 'X')) /* Pour la case en bas a gauche quand i = 27 et j = 0 */
			{
				tab[i - 1][j] = ' ';
				tab[i][j + 1] = ' ';
				return (tab);
			}
		}
		else if (j == size)
		{
			if ((tab[i - 1][j] == 'X') && (tab[i][j - 1] == 'X')) /* Pour la case en bas a droite quand i = 27 et j = 27 */
			{
				tab[i - 1][j] = ' ';
				tab[i][j - 1] = ' ';
				return (tab);
			}
		}
		else
		{
			if ((tab[i][j - 1] == 'X') && (tab[i][j + 1] == 'X') && (tab[i][j - 1] == 'X')) /* Pour la derniere ligne quand i = 27*/
			{
				tab[i][j - 1] = ' ';
				tab[i - 1][j] = ' ';
				return (tab);
			}
		}
	}
	
	else if (j == 0)
		{
			if ((tab[i][j + 1] == 'X') && (tab[i + 1][j] == 'X') && (tab[i - 1][j] == 'X')) /* Pour la colone de gauche quand j = 0 */
			{
				tab[i + 1][j] = ' ';
				tab[i][j + 1] = ' ';
				return (tab);
			}
			
		}
		
	else if (j == size)
		{
			if ((tab[i][j - 1] == 'X') && (tab[i + 1][j] == 'X') && (tab[i - 1][j] == 'X')) /* Pour la colone de gauche quand j = 0 */
			{
				tab[i - 1][j] = ' ';
				tab[i][j - 1] = ' ';
				return (tab);
			}
			
		}
		else
		{
			if ((tab[i - 1][j] == 'X') && (tab[i][j + 1] == 'X') && (tab[i][j + 1] == 'X') && (tab[i][j - 1] == 'X')) /* Pour le reste */
				{
					tab[i][j - 1] = ' ';
					tab[i - 1][j] = ' ';
					return (tab);
				}
		}
	return (tab);
}

char	**check_exit(char **tab, int exit_orientation, int exit_position, int size)
{
	if (exit_orientation == 0)
		tab[0][exit_position] = ' ';
		
	else if (exit_orientation == 1)
		tab[exit_position][size] = ' ';
		
	else if (exit_orientation == 2)
		tab[size][exit_position] = ' ';
	
	else if (exit_orientation == 3)
		tab[exit_position][0] = ' ';
	return (tab);;
}
