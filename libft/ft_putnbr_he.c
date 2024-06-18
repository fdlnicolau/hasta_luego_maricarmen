/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_he.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:32:27 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/02 17:18:06 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_chex(unsigned int nbr, int *c)
{
	if (nbr >= 16)
	{
		ft_chex((nbr / 16), c);
		ft_chex((nbr % 16), c);
	}
	if (nbr <= 9)
	{
		ft_putchar((nbr % 10 + '0'));
		*c = *c + 1;
	}
	else if (nbr < 16 && nbr > 9)
	{
		ft_putchar(nbr - 10 + 'A');
		*c = *c + 1;
	}
}

int	ft_putnbr_he(unsigned int nbr)
{
	int	c;

	c = 0;
	ft_chex (nbr, &c);
	return (c);
}
