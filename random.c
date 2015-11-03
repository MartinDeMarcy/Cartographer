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

int	my_random(int nb)
{
 	 nb = (1103515245 * nb + 12345 ) % 2147483647;
 	 if (nb < 0)
 	 	nb = nb * -1;
 	return (nb);
}
