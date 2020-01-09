/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_prueba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:43:11 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/09 16:35:42 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	float	pi = 3.1415;	
	int 	num;
	int 	exp;
	int		mantisa;

	num = *((int *)&pi);
	mantisa = num & 0x7FFFFF;
	exp = (num & 0x7F800000) >> 24;
	printf("num: 0x%08x , exponente: 0x%02x y mantisa: 0x%06x", num, exp, mantisa);
	//printf("numero decimal: %08x, %08x", *((int *)&pi), num);
}
