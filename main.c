/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:39:23 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/21 20:56:46 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main(void)
{
	ft_printf("la primera letra es la %c, la segunda la %c y la última es la %c\n", 'a', 'b', 'z');
	ft_printf("me llamo %s\n", "victor");
}
