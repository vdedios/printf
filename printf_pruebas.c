/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pruebas.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:42:20 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/13 17:21:52 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
** %[flags][width][.precision][lenght]type
** 		[flags]: num, 0, +, -, #,  ,’
** 		[width]: *
** 		[precision]: ?
** 		[lenght]: l, ll, h, hh
** types: c, s, p, d, r, u, x, X, n, f, g, e
*/

int main(void)
{
	char	c = 'a';//c
	char	*s = "hola";//s
	char	*p; /*p*/ p = malloc(1);
	int		num = 3;//d
	
	//---PROBAR CON OTROS TIPOS DE VARIABES!!!----
	//FLAGS
	
		//número
		printf("número_salida:%5d\n", num);

		//0
		printf("0_salida:%05d\n", num);

		//+
		printf("+_salida:%+d\n", num);
		
		//-
		printf("-_salida:%-2d\n", num);
		
		//BONUS-> probar una vez tenga claras las variables
		//ya que sólo fucionan con algunas
			//#
			//[ ]
			//’
		//**COMBOS**
		printf("+5_salida:%+5d\n", num);
		printf("+05_salida:%+05d\n", num);
		printf("-_salida:%+-d\n", num);
}
