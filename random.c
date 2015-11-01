/*
** random.c for random.c in /home/pras_m/rendu/cursus_dedie/Cartographer
** 
** Made by PRAS Martin
** Login   <pras_m@epitech.net>
** 
** Started on  Wed Oct 21 21:49:51 2015 PRAS Martin
** Last update Wed Oct 21 21:49:55 2015 PRAS Martin
*/

#include <time.h>

int	my_random()
{
	int	a;
	int	m;
	int	nb;
	
	nb = time(0);
	my_put_nbr(nb);
	a = 16807;
	m = 0x7FFFFFFF;
 	nb = (a * nb) % m;
 	return (nb);
}
