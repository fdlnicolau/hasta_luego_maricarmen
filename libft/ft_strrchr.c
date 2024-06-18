/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:51:50 by lnicolau          #+#    #+#             */
/*   Updated: 2024/04/01 21:07:45 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*a;
	int		i;

	a = (char *)str;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (a[i] == (char)c)
			return (&a[i]);
		i--;
	}
	return (0);
}
