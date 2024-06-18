/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:07:57 by lnicolau          #+#    #+#             */
/*   Updated: 2023/11/07 20:18:50 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*En términos más simples,
si estás comparando números en dos listas uno por uno,
puedes decir que la lista que tiene un número más grande en la misma posición es
la que es "mayor" en ese punto. Por ejemplo,
si en la Lista 1 el número es 5 y en
la Lista 2 el número es 3,
puedes decir que la Lista 1 es "mayor" en ese punto.*/

#include "libft.h"

int	ft_memcmp(const void *st1, const void *st2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)st1;
	s2 = (unsigned char *)st2;
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (n)
		{
			s1++;
			s2++;
		}
	}
	return (0);
}
