/*
** src2.c for src2.c in /home/pras_m/rendu/cursus_dedie/Cartographer
** 
** Made by PRAS Martin
** Login   <pras_m@epitech.net>
** 
** Started on  Fri Oct 30 21:49:10 2015 PRAS Martin
** Last update Fri Oct 30 21:49:12 2015 PRAS Martin
*/

#include "include/cartographer.h"

void	my_putchar_err(char c)
{
	write(2, &c, 1);
}

void	my_puterr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		my_putchar_err(str[i++]);
	}
}
