/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-dios <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:35:34 by vde-dios          #+#    #+#             */
/*   Updated: 2019/12/20 17:31:37 by vde-dios         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Versión simplificada sin va_args que saca las marcas de cadena
//ojo funciones de string.h 

#include "libft/libft.h"
#include "printf.h"
#include <stdarg.h>

//ft_extract_format -> extrae el formato
//Falta que chequee errores de formato -> como va por zonas, sería interesante que se comportara como un atoi
char	*ft_extract_format(const char *s)
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

//Ejecuta formato. Avanza s en format_spec y concatena en print_buf el valor a extraído y formateado
char	*ft_formater(const char **s, char *printf_buf, va_list args)
{
	char	*format_spec;
	
	format_spec = ft_extract_format(*s);
	printf("extracted!%s\n", format_spec);
	//1 -> extract
	//2 -> ft_analyse (errors)
	//3 -> ft_type_conv
	//4 -> ft_flag_conv	
	//5 -> copy to buf and forward string
		//print_buf = ft_realloc(ft_formater(format_spec, print_buf));
		//*s = *s + ft_strlen(format_spec) - 1;
	return (0);
}

//(ft_read)
int		ft_printf(const char *s, ...)
{
	char	*print_buf;
	va_list args;

	va_start(args, s);
	print_buf = NULL;
	while(*s)
	{
		if (*s == '%')
			ft_formater(&s, print_buf, args);
		//ft_realloc (s, printf_buf); -> ir guardando lo que no es formato
		s++;
	}
	va_end(args);
	//ft_putstr_fd(print_buf, 1);
	return (ft_strlen(print_buf));
}
