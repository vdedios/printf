/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_itoa_special.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:19:03 by vde-dios          #+#    #+#             */
/*   Updated: 2020/01/11 17:44:44 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/ft_itoa_special.c"

int main()
{
	int		a = 1;
	char	*b;

	b = ft_itoa_special(a);
	printf("num: %s", b);
}