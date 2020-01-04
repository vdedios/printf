/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:39:23 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/04 21:18:22 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main(void)
{
	char	*str = "manuel";
	char	c = 'm';
	int		dir;
	int		neg = -43;
	int		pos = 32423;

	dir = (int)str;	
	ft_printf("la primera letra es la %c, la segunda la %c y la última es la %c\n", 'a', 'b', 'z');
	ft_printf("me llamo %s. Yo me llamo %s y mi nombre empieza por la letra %c\n", "victor", str, c);
	printf("mi dirección de memoria es %p o %d y en hex es %x\n", str, dir, dir);
	ft_printf("mi dirección de memoria es esta: %p\n", str);
	ft_printf("mi dirección de memoria es esta: %d\n", dir);
	printf("un negativo: %d\n", neg);
	ft_printf("un negativo: %d\n", neg);
	ft_printf("mi dirección de memoria es esta: %i\n", dir);
	printf("esto es un negativo:%u y esto un positivo:%u\n", neg, pos);
	ft_printf("esto es un negativo:%u y esto un positivo:%u\n", neg, pos);
	ft_printf("esto es un x:%x y esto un X:%X\n", pos, pos);
	printf("esto es un x:%x y esto un X:%X\n", pos, pos);
}
