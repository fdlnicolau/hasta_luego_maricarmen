/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:30:31 by lnicolau          #+#    #+#             */
/*   Updated: 2023/10/30 18:02:54 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	count, size_t	size)
{
	void	*dic;

	dic = malloc(count * size);
	if (dic == NULL)
		return (NULL);
	ft_bzero(dic, count * size);
	return (dic);
}

// #include <stdio.h>
// #include "libft.h"
// int main() 
// {
//     size_t num_elementos = 5;
//     size_t tamaño_elemento = sizeof(int);

//     int *array = (int *)calloc(num_elementos, tamaño_elemento);

//     if (array == NULL) {
//         fprintf(stderr, "Error al asignar memoria con calloc.\n");
//         return 1;
//     }
//     for (size_t i = 0; i < num_elementos; i++) {
//         printf("array[%zu] = %d\n", i, array[i]);
//     }

// }