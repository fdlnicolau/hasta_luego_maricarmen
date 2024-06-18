/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:13:17 by lnicolau          #+#    #+#             */
/*   Updated: 2024/02/08 13:46:16 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*concatenation;
	int		i;
	int		j;

	i = -1;
	j = 0;
	concatenation = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1,
			sizeof(char));
	if (concatenation == NULL)
		return (0);
	while (s1[++i])
		concatenation[i] = s1[i];
	while (s2[j])
		concatenation[i++] = s2[j++];
	free (s1);
	return (concatenation);
}
