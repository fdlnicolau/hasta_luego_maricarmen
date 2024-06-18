/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:36:48 by lnicolau          #+#    #+#             */
/*   Updated: 2024/03/26 14:47:49 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*La función ft_strjoin toma dos cadenas (s1 y s2),
 las concatena juntas y devuelve una nueva cadena que contiene
 la concatenación, gestionando la memoria adecuadamente para evitar
 fugas de memoria.*/
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		k;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = (i + j + 1);
	s3 = (char *)malloc (i + j + 1);
	if (s3 != NULL)
	{
		s3[0] = '\0';
		ft_strlcat (s3, s1, k);
		ft_strlcat (s3, s2, k);
		return (s3);
	}
	return (NULL);
}
