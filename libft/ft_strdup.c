/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:28:16 by lnicolau          #+#    #+#             */
/*   Updated: 2023/10/30 19:09:58 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Toma una *cadena de carcteres y crea una nueva 
copia exacta de esa cadena en otra ubicacion de memoria*/
#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	size_t	i;
	char	*dest;

	i = 0;
	len = ft_strlen(str);
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
	{
		return (NULL);
	}
	while (i <= len)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}
