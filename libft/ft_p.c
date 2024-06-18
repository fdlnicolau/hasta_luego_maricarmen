/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:33:48 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/02 17:17:07 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_p(void *p)
{
	int	c;

	c = 0;
	if (!p)
	{
		ft_putstr("0x0");
		return (3);
	}
	else
	{
		ft_putstr("0x");
		c = 2 + ft_putnbr_x((unsigned long)p);
	}
	return (c);
}
