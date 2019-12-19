/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pruebas.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:42:20 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/19 16:08:34 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
//#include <locale.h>
//setlocale(LC_NUMERIC, "en_US.UTF-8");
#define LC_NUMERIC	"en_US.UTF-8"

/*
** %[flags][width][.precision][lenght]type
** 		[flags]: num, 0, +, -, #,  ,'
** 		[width]: *
** 		[precision]: ?
** 		[lenght]: l, ll, h, hh
** types: c, s, p, d, i, u, x, X, n, f, g, e
*/

int main(void)
{
	int				num = 30000000;
	int				neg = -10;
	float			var_dec = 3023.9487;
	
	//---PROBAR CON OTROS TIPOS DE VARIABES!!!----
	//FLAGS
	
		//número
		printf("número_salida:%5d\n", num);
		printf("número_salida:%5.5d\n", num);
		printf("número_salida:%.5f\n", 5.24);

		//0
		printf("0_salida:%05d\n", num);

		//+
		printf("+_salida:%+d\n", num);
		
		//-
		printf("-_salida:%-2d\n", num);
		
		//BONUS
			//# -> funciona solo con f, e, g y x/X
			printf("#f_salida:%#f y f_salida:%f\n", var_dec, var_dec);
			printf("#e_salida:%#e y e_salida:%e\n", var_dec, var_dec);
			printf("#g_salida:%#g y g_salida:%g\n", var_dec, var_dec);
			printf("#x_salida:%#x y x_salida:%x\n", num, num);
			//[ ]
			printf("[ ]d_salida:% d y d_salida:%d\n", neg, neg);
			printf("[ ]d_salida:%    d y d_salida:%d\n", num, num);
			//'
			printf("'d_salida:%'d y d_salida:%d\n", 16728367, 16728367);

		//**COMBOS**
		printf("+5_salida:%+5d\n", num);
		printf("+05_salida:%+05d\n", num);
		printf("-_salida:%+-d\n", num);

	//WIDTH
			printf("width_salida:%*d\n", 6, 127);
			printf("width_salida:%*d\n", 1, 127);

	//PRECISION
			printf("precision_salida:%.*d\n", 6, 127);
			printf("precision_salida:%.*d\n", 1, 127);
			printf("precision_salida:%.*f y %f\n", 1, 127.3, 127.3);

	//WIDTH + PRECISION
			printf("pre+width_salida:%*.*d\n", 6, 1,  127);

	//LENGHT
			//l
			long l = 10;
			printf("l_salida:%ld\n", l);
			//ll
			long long ll = 10;
			printf("ll_salida:%lld\n", ll);
			//hh
			char a = 'a';
			printf("hh_salida:%hhd\n", a);
			//h
			short s = 10;
			printf("h_salida:%hd\n", s);

	//VAR TYPES
		int		a_var = -13;
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
