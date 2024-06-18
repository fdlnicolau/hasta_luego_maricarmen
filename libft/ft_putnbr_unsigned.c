/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:25:46 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/02 17:18:39 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_len(long number)
{
	int	len;

	len = 1;
	while (number > 9)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	c;

	c = ft_len(n);
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
	}
	ft_putchar((n % 10) + '0');
	return (c);
}
