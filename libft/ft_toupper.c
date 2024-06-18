/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:54:02 by lnicolau          #+#    #+#             */
/*   Updated: 2023/10/30 19:03:51 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Convierte una carácter entre la a y la z (minúsculas)
a mayúsculas. Si es mayúscula u otro símbolo no se altera.
Según la implementación, es muy posible que falle con c
aracteres internacionales (como á, ñ).*/
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
