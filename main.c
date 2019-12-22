/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:39:23 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/22 17:37:33 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main(void)
{
	char	*str = "manuel";
	char	c = 'm';
	int		dir;

	dir = (int)str;	
	ft_printf("la primera letra es la %c, la segunda la %c y la última es la %c\n", 'a', 'b', 'z');
	ft_printf("me llamo %s. Yo me llamo %s y mi nombre empieza por la letra %c wena\n", "victor", str, c);
	printf("mi dirección de memoria es: %p o %d\n", str, dir);
	ft_printf("mi dirección de memoria es: %p o %d\n", str, dir);
}
