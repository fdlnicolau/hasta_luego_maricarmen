/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:54:49 by lnicolau          #+#    #+#             */
/*   Updated: 2023/10/30 19:01:55 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Convierte una carácter entre la a y la z (minúsculas)
a mayúsculas. Si es mayúscula u otro símbolo no se altera.
Según la implementación,
	es muy posible que falle con caracteres internacionales (como á, ñ).*/
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
