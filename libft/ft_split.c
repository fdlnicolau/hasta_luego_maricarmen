/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:20:29 by lnicolau          #+#    #+#             */
/*   Updated: 2023/11/09 16:19:32 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_substrings(const char *s, char delimiter)
{
	int	count;
	int	word;

	word = 0;
	count = 0;
	while (s[count])
	{
		if (s[count] != delimiter)
		{
			word ++;
			while (s[count] != delimiter && s[count + 1] != '\0')
				count++;
		}
		count++;
	}
	return (word);
}

static size_t	ft_word_size(char const *s, char c, int de)
{
	int	size;

	size = 0;
	while (s[de] != c && s[de])
	{
		size++;
		de++;
	}
	return (size);
}

static char	**ft_free(char **s2d)
{
	int	i;

	i = 0;
	while (s2d[i])
	{
		free(s2d[i]);
		i++;
	}
	free(s2d);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	size_t	j;
	char	**s2d;

	j = 0;
	i = 0;
	s2d = (char **) malloc (sizeof (char *) * (ft_count_substrings(s, c) + 1));
	if (s2d == NULL)
		return (0);
	while (j < ft_count_substrings(s, c) && s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		s2d[j] = ft_substr(s, i, ft_word_size(s, c, i));
		if (s2d[j] == NULL)
			return (ft_free(s2d));
		i = i + ft_word_size(s, c, i);
		j++;
	}
	s2d[j] = NULL;
	return (s2d);
}
