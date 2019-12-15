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
#include <stdlib.h>

/*
** %[flags][width][.precision][lenght]type
** 		[flags]: num, 0, +, -, #,  ,’
** 		[width]: *
** 		[precision]: ?
** 		[lenght]: l, ll, h, hh
** types: c, s, p, d, i, u, x, X, n, f, g, e
*/

int main(void)
{
	int	num = 3;//d
	
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

	//VAR TYPES

		int	a_var = -13;
		int 	p_var;
		float	f_var = 10.5;
		double	d_var = 120.00000078;

		//%c
		//%s
		//%p
		//%d
		//%i
		printf("i_salida:%d\n", a_var);
		//%u
		printf("u_salida:%u\n", a_var);
		//%x
		printf("x_salida:%x\n", a_var);
		//%X
		printf("X_salida:%X\n", a_var);
		//%n
		printf("n_salida:%n\n", &p_var);
		printf("n_salida:%d\n", p_var);
		//%f
		printf("f_salida:%f\n", f_var);
		printf("f_salida:%f\n", d_var);
		//%e
		printf("e_salida:%e\n", f_var);
		printf("e_salida:%e\n", d_var);
		//%g
		printf("g_salida:%g\n", f_var);
		printf("g_salida:%g\n", d_var);
		
}
