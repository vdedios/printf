/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:39:23 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/14 13:50:41 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main(void)
{
	char	*str = "manuel";
	char	c = 'm';
	int		d = 1;
	int		dir = 0;
	long int	dir2;
	int		neg = -43;
	int		pos = 32423;

	// %s y %c
	ft_printf("la primera letra es la %c, la segunda la %c y la última es la %c\n", 'a', 'b', 'z');
	ft_printf("me llamo %s. Yo me llamo %s y mi nombre empieza por la letra %c\n\n", "victor", str, c);

	// %d, %p
	dir2 = (long int)str;	
	printf("OG printf %p, %ld, %x\n", str, dir2, 30);
	ft_printf("ft_printf %p, %ld, %lx\n\n", str, dir2, 30);
	dir2 = (long int)&c;	
	printf("mi dirección de memoria es con & de c: %p o %ld y en hex es %lx\n", &d, dir2, dir2);
	ft_printf("mi dirección de memoria es con & de c: %p o %ld y en hex es %lx\n\n", &d, dir2, dir2);

	ft_printf("un negativo: %d\n\n", neg);
	ft_printf("mi dirección de memoria es esta: %i\n", dir);

	// %u
	printf("esto es un negativo:%u y esto un positivo:%u\n", neg, pos);
	ft_printf("esto es un negativo:%u y esto un positivo:%u\n", neg, pos);

	// %x y %X
	ft_printf("esto es un x:%x y esto un X:%X\n", pos, pos);
	printf("esto es un x:%x y esto un X:%X\n", pos, pos);

	// %f %e y %g	
	float	pi_l = 0;
	//float	pi_l = 0.000312255;
	//float	pi_l = 0.0312255;
	//float	pi_l = 312222.55;
	//float	pi_l = 3122.55;
	
	//float	pi_l = 987234973234398732.55;
	//float	pi_l = 98;
	//float	pi_l = 95;
	//float	pi_l = 0.312255;
	//float	pi_l = 3.1;
	//float	pi_l = -3.012300;
	//float	pi_l = 3.0100;
	//float	pi_l = 3.12255;
	//float	pi_l = 3.141499996185302734375; 
	//probar infinitos y nans
	printf("el número pi vale: %f %e %g\n", pi_l, pi_l, pi_l);
	ft_printf("el número pi vale: %f %e %g\n", pi_l, pi_l, pi_l);

	printf("el número pi vale: %F %E %G\n", pi_l, pi_l, pi_l);
	ft_printf("el número pi vale: %F %E %G\n", pi_l, pi_l, pi_l);
	double *infinity;
	long long int inf;
	inf = 0x7F80000000000000;
	infinity = (double *)&inf;
	printf("esto es un infinito %f %e %g\n", -1.0/0, 0.0/0, 1.0/0);
	ft_printf("esto es un infinito %f %e %g\n", -1.0/0, 0.0/0, 1.0/0);

	// %n
	int cc;

	ft_printf("aadeberias %g escribir 33 caracteres: %n", pi_l, &cc);	
	printf("%d\n", cc);
	printf("aadeberias %g escribir 33 caracteres: %n", pi_l, &cc);	
	printf("%d\n", cc);
}
