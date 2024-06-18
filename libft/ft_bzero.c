/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:23:23 by lnicolau          #+#    #+#             */
/*   Updated: 2024/03/26 14:45:51 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*stablecer en cero (es decir, borrar) un
bloque de memoria, especificado por un puntero
s y un tamaño n.*/
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
