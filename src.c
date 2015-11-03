/*
** src.c for Makefile in /home/pras_m/rendu/cursus_dedie/Cartographer
** 
** Made by PRAS Martin
** Login   <pras_m@epitech.net>
** 
** Started on  Wed Oct 21 19:45:33 2015 PRAS Martin
** Last update Wed Oct 21 19:45:37 2015 PRAS Martin
*/

#include "include/cartographer.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putstr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		my_putchar(str[i++]);
}

int	my_strlen(char *str)
{
  int	nb;

  nb = 0;
  while (str[nb])
      nb++;
  return (nb);
}

int	my_getnbr(char *str)
{
  int	a;
  int	b;
  int	c;

  a = 1;
  b = 0;
  c = 0;
  while ((str[b] == '-') || (str[b] == '+'))
    {

      if (str[b] == '-')
	{
	  a = a * (-1);
	}
      b = b + 1;
    }
  while ((str[b] >= 48) && (str[b] <= 57))
    {
      c = c * 10;
      c = c + str[b] - 48;
      b = b + 1;
    }
  return (c * a);
}

int	my_put_nbr(int nb)
{
  if (nb == 0)
    {
      my_putchar(48);
      return (0);
    }
  if (nb < 0)
    {
      nb = -nb;
      my_putchar(45);
    }
  if (nb < 10)
    {
      my_putchar(48 + nb);
      return (0);
    }
  my_put_nbr(nb / 10);
  my_putchar(nb % 10 + 48);
  return (0);
}
