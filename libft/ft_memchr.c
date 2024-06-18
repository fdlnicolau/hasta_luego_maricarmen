/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:41:40 by lnicolau          #+#    #+#             */
/*   Updated: 2024/03/26 14:46:37 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
memchr en C busca un byte (como una letra o número) en un montón de datos y
te dice si lo encontró o no, y si lo encuentra, te dice dónde está.*/
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
