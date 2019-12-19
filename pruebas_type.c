/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:08:45 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/19 17:25:00 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	//PRUEBAS CON C
	char c;

	c = 'a';
		//FLAGS
			//num
			printf("%3c\n", c);
			//0
			//NO -> printf("%0c\n", c);
			//+
			//NO -> printf("%+c\n", c);
			//-
			printf("%-c\n", c);
			//#
			//NO -> printf("%#c\n", c);
			//[ ]
			//NO -> printf("% c\n", c);
			//'
			//NO -> printf("%'c\n", c);

	//PRUEBAS CON S
	char *str = "hola que tal";

		//FLAGS
			//num
			printf("%3s\n", str);
			//0
			//NO -> printf("%0c\n", c);
			//+
			//NO -> printf("%+c\n", c);
			//-
			printf("%-c\n", c);
			//#
			//NO -> printf("%#c\n", c);
			//[ ]
			//NO -> printf("% c\n", c);
			//'
			//NO -> printf("%'c\n", c);


	//PRUEBAS CON P
		//FLAGS
			//num
			printf("%3p\n", str);
			//0
			// NO -> printf("%0p\n", str);
			//+
			// NO -> printf("%+p\n", str);
			//-
			printf("%-p\n", str);
			//#
			// NO -> printf("%#p\n", str);
			//[ ]
			// NO -> printf("% p\n", str);
			//'
			// NO -> printf("%'p\n", str);
			

	//PRUEBAS CON N/I
	int i;

	i = 35;
		//FLAGS
			//num
			printf("%3d\n", i);
			printf("%3i\n", i);
			//0
			printf("%0d\n", i);
			printf("%0i\n", i);
			//+
			printf("%+d\n", i);
			printf("%+i\n", i);
			//-
			printf("%-d\n", i);
			printf("%-i\n", i);
			//#
			//printf("%#d\n", i);
			//printf("%#i\n", i);
			//[ ]
			printf("% d\n", i);
			printf("% i\n", i);
			//'
			printf("%'d\n", i);
			printf("%'i\n", i);


	//PRUEBAS CON N/I
		unsigned q;

		q = 35;
		//FLAGS
			//num
			printf("%3u\n", q);
			//0
			printf("%0u\n", q);
			//+
			//printf("%+u\n", q);
			//-
			printf("%-u\n", q);
			//#
			//printf("%#u\n", q);
			//[ ]
			//printf("% u\n", q);
			//'
			printf("%'u\n", q);

	//PRUEBAS CON x/X
		int char_p;

		char_p = 0x123;
		//FLAGS
			//num
			printf("%3x\n", char_p);
			printf("%3X\n", char_p);
			//0
			printf("%0x\n", char_p);
			printf("%0X\n", char_p);
			//+
			//printf("%+x\n", char_p);
			//printf("%+X\n", char_p);
			//-
			printf("%-x\n", char_p);
			printf("%-X\n", char_p);
			//#
			printf("%#x\n", char_p);
			printf("%#X\n", char_p);
			//[ ]
			//printf("% x\n", char_p);
			//printf("% X\n", char_p);
			//'
			//printf("%'x\n", char_p);
			//printf("%'X\n", char_p);
	

	//PRUEBAS CON x/X
		int		*int_p = NULL;

		//FLAGS
			//stock
			printf("%n\n", int_p);
			//num
			//printf("%3n\n", int_p);
			//0
			//printf("%0n\n", int_p);
			//+
			//printf("%+n\n", int_p);
			//-
			//printf("%-n\n", int_p);
			//#
			//printf("%#n\n", int_p);
			//[ ]
			//printf("% n\n", int_p);
			//'
			//printf("%'n\n", int_p);

	//PRUEBAS CON f
		float	b;

		b = 12343988433.345349;
		//FLAGS
			//num
			printf("%3f\n", b);
			//0
			printf("%0f\n", b);
			//+
			printf("%+f\n", b);
			//-
			printf("%-f\n", b);
			//#
			printf("%#f\n", b);
			//[ ]
			printf("% f\n", b);
			//'
			printf("%'f\n", b);

	//PRUEBAS CON e

		//FLAGS
			//num
			printf("%3e\n", b);
			//0
			printf("%0e\n", b);
			//+
			printf("%+e\n", b);
			//-
			printf("%-e\n", b);
			//#
			printf("%#e\n", b);
			//[ ]
			printf("% e\n", b);
			//'
		//	printf("%'e\n", b);
		
	//PRUEBAS CON g

		//FLAGS
			//num
			printf("%3g\n", b);
			//0
			printf("%0g\n", b);
			//+
			printf("%+g\n", b);
			//-
			printf("%-g\n", b);
			//#
			printf("%#g\n", b);
			//[ ]
			printf("% g\n", b);
			//'
			printf("%'g\n", b);
		
}
