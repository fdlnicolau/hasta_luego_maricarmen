/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:36:38 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/02 17:18:57 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_c(unsigned long nbr, int *c)
{
	if (nbr >= 16)
	{
		ft_c((nbr / 16), c);
		ft_c((nbr % 16), c);
	}
	if (nbr <= 9)
	{
		ft_putchar(nbr % 10 + '0');
		*c = *c + 1;
	}
	else if (nbr < 16 && nbr > 9)
	{
		ft_putchar(nbr - 10 + 'a');
		*c = *c + 1;
	}
}

int	ft_putnbr_x(unsigned long nbr)
{
	int	c;

	c = 0;
	ft_c(nbr, &c);
	return (c);
}
