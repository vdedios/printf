/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:35:34 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/12 20:46:55 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Versión simplificada sin va_args que saca las marcas de cadena
//ojo funciones de string.h 

#include "libft.h/libft.h"
#include "printf.h"

//Falta que chequee errores de formato -> como va por zonas, sería interesante que se comportara como un atoi
static char	*ft_get_format(const char *s)
{
	int 	l;
	int		l_types;
	char	*types;

	l = 0;
	types = "cspdiuxXnfge";
	l_types = ft_strlen(types);
	while (s[l] != *types++ && s[l])
	{
		if (!*types)
		{
			types = types - l_types;
			l++;
		}
	}
	return (ft_substr(s, 0, l + 2));
}

int			ft_printf(const char *s)
{
	char *format;
	while(*s)
	{
		if (*s == '%')
		{
			format = ft_get_format(s);
			printf("%s\n", format);
			s = s + ft_strlen(format) - 1;
			printf("%s\n", s);
		}
		s++;
	}
	return (0);
}
