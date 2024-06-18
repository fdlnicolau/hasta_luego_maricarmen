/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:07:52 by lnicolau          #+#    #+#             */
/*   Updated: 2024/02/08 13:44:10 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*duplicate_string(char *s1)
{
	char			*new_chain;
	unsigned int	i;

	if (!s1)
		return (NULL);
	i = -1;
	new_chain = (char *)ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	if (!new_chain)
		return (NULL);
	while (s1[++i])
		new_chain[i] = s1[i];
	return (new_chain);
}

char	*update_and_extract_next_line(char *static_s)
{
	char	*after_line_break;

	after_line_break = duplicate_string(ft_strchr(static_s, '\n'));
	free(static_s);
	if (after_line_break)
		static_s = duplicate_string(after_line_break + 1);
	else
		static_s = NULL;
	return (free(after_line_break), static_s);
}

char	*reader(char *static_s, int fd)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(static_s, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(static_s), NULL);
		buffer[bytes_read] = '\0';
		if (!static_s)
			static_s = ft_calloc(1, 1);
		static_s = gnl_strjoin(static_s, buffer);
		if (!*static_s)
			return (free(static_s), free(buffer), buffer = NULL, NULL);
	}
	return (free(buffer), static_s);
}

char	*get_next_line(int fd)
{
	static char		*static_s;
	char			*line;
	int				i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	static_s = reader(static_s, fd);
	if (!static_s)
		return (NULL);
	while (static_s[i] != '\n' && static_s[i])
		i++;
	line = ft_substr(static_s, 0, i + 1);
	static_s = update_and_extract_next_line(static_s);
	return (line);
}
