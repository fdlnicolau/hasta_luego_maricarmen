/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:49:03 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/02 17:17:35 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_type(char c, va_list elee)
{
	int	posc;

	posc = 0;
	if (c == 'c')
		posc += ft_putchar(va_arg(elee, int));
	else if (c == 's')
		posc += ft_putstr(va_arg(elee, char *));
	else if (c == 'p')
		posc += ft_p(va_arg(elee, void *));
	else if (c == 'd')
		posc += ft_putnbr(va_arg(elee, int));
	else if (c == 'i')
		posc += ft_putnbr(va_arg(elee, int));
	else if (c == 'u')
		posc += ft_putnbr_unsigned(va_arg(elee, unsigned int));
	else if (c == 'x')
		posc += ft_putnbr_x(va_arg(elee, unsigned int));
	else if (c == 'X')
		posc += ft_putnbr_he(va_arg(elee, unsigned int));
	else if (c == '%')
		posc += ft_putchar('%');
	return (posc);
}

int	ft_printf(const char *str, ...)
{
	va_list	elee;
	int		i;
	int		posc;

	i = 0;
	posc = 0;
	va_start(elee, str);
	if (write (1, "", 0) == -1)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			posc += ft_type(str[i], elee);
		}
		else
			posc += ft_putchar(str[i]);
		i++;
	}
	va_end (elee);
	return (posc);
}
