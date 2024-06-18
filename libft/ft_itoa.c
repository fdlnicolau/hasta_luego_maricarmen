/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:47:29 by lnicolau          #+#    #+#             */
/*   Updated: 2023/11/13 18:31:49 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_comb(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = n;
	while (j)
	{
		j /= 10;
		i++;
	}
	if (n <= 0)
		i++;
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	while (i--)
	{
		ptr[i] = ft_comb(n % 10) + '0';
		n /= 10;
	}
	if (ptr[0] == '0' && ptr[1] != '\0')
		ptr[0] = '-';
	return (ptr);
}
