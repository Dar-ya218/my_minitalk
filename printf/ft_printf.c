/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:10:23 by dabochko          #+#    #+#             */
/*   Updated: 2024/03/12 11:29:41 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//#include <stdio.h>
//#include <stddef.h>

/* Toma una cadena de formato y un número variable de argumentos.
Utiliza	va_start(void) para inicializar una lista de argumentos args.
Luego, recorre la cadena de formato carácter por carácter. Si
encuentra un carácter %, espera que el siguiente carácter sea un
especificador de formato (c, s o d en este caso) y llama a la
función correspondiente para escribir el siguiente argumento en
la salida estándar. Si el carácter no es un %, simplemente lo
escribe en la salida estándar. Finalmente, utiliza
va_end() para limpiar args.*/

static int	ft_selector(va_list args, char const place)
{
	int	size;

	size = 0;
	if (place == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (place == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (place == 'd' || place == 'i')
		size += ft_putnbr(va_arg(args, int));
	else if (place == 'u')
		size += ft_putunbr(va_arg(args, unsigned int));
	else if (place == 'x' || place == 'X')
		size += ft_puthex(va_arg(args, unsigned int), place);
	else if (place == 'p')
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		size += 2 + ft_putptr(va_arg(args, unsigned long));
	}
	else if (place == '%')
		size += ft_putchar(place);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		size;
	int		size2;
	va_list	args;

	i = 0;
	size = 0;
	size2 = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			size = ft_selector(args, format[++i]);
		else
			size = ft_putchar(format[i]);
		if (size == -1)
			return (-1);
		if (format[i] != '\0')
			i++;
		size2 += size;
	}
	va_end(args);
	return (size2);
}
/*
int	main(void)
{
	int	i;
	int	i;
	int	j;

	i = ft_printf("hola %c %s %i %d %u %x %X %p%\0 57",\
	'c', NULL, 547, -13, -1, 255, 255, &i);
	//printf("\n%d\n", i);
	ft_printf("%"); // '%' '\0' == 2
	return (0);
}*/
/*
int	main(void)
{
	i = printf ("%%%c%s%p%u%d%i%x%X\n",\
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	j = ft_printf ("%%%c%s%p%u%d%i%x%X\n",\
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	printf("ORIGINAL %d\nMIO %d", i, j);
	return ((0));
}
*/
