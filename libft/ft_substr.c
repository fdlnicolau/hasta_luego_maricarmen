/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:16:31 by lnicolau          #+#    #+#             */
/*   Updated: 2023/11/13 18:43:07 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//esta función extrae una porción específica de una
// cadena más larga y la devuelve como una nueva cadena.

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*sub;
	char	*empty_str;

	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
	{
		empty_str = (char *)malloc(1);
		if (empty_str == NULL)
			return (NULL);
		empty_str[0] = '\0';
		return (empty_str);
	}
	if (len < (s_len - start))
		sub_len = len;
	else
		sub_len = s_len - start;
	sub = (char *)malloc(sub_len + 1);
	if (sub == NULL)
		return (NULL);
	ft_memcpy(sub, s + start, sub_len);
	sub[sub_len] = '\0';
	return (sub);
}
