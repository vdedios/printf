/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:14:20 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/22 19:33:30 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

/*
** <<c>> type conversion
*/
char	*ft_c_conv(char *format_info, va_list args)
{
	char *aux;
	(void)format_info;

	if (!(aux = malloc(sizeof(char))))
		return (NULL);
	//1º gestión de error
	//2º conversión de tipo
	*aux = va_arg(args, int);
	return (aux);
}

/*
** <<s>> type conversion
*/
char	*ft_s_conv(char *format_info, va_list args)
{
	char	*aux;
	char	*aux2;
	int		l;
	(void)format_info;

	//1º gestión de error
	//2º conversión de tipo
	aux = va_arg(args, char *);
	l = ft_strlen(aux);
	if (!(aux2 = malloc(l * sizeof(char) + 1)))
		return (NULL);
	while (*aux)
		*aux2++ = *aux++;
	*aux2 = '\0';
	return (aux2 - l);
}

/*
** <<p>> type conversion
*/
char	*ft_p_conv(char *format_info, va_list args)
{
	int		dir;
	char	*aux2;
	int		l;
	(void)format_info;

	//1º gestión de error
	//2º conversión de tipo
	aux = (int)va_arg(args, char *);
	l = ft_strlen(aux);
	if (!(aux2 = malloc(l * sizeof(char) + 1)))
		return (NULL);
	while (*aux)
		*aux2++ = *aux++;
	*aux2 = '\0';
	return (aux2 - l);
}
/*
char	*ft_di_conv(char *format_info, va_list args);
char	*ft_u_conv(char *format_info, va_list args);
*/
