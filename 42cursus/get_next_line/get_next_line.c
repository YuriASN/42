/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:59:28 by ysantos-          #+#    #+#             */
/*   Updated: 2022/04/25 21:43:59 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static size_t	get_line_size(char *str)
{
	int		count;

	count = 0;
	while (str[count])
	{
		++count;
	}
	return (count);
}

/* static size_t	get_line_size(int fd)
{
	int		count;
	char	c;

	count = 0;
	while (c != '\n' || fd)
	{
		read(fd, &c, 1);
		++count;
	}
	return (count);
} */

static size_t	buf_to_str(char *str, const char *buffer, size_t i)
{
	size_t	o;

	o = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		str[o] = buffer[i];
		++i;
	}
	if (!buffer[i])
		i = 0;
	return (i);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*str;
	static size_t	i;

	if (!fd)
		return (0);
	i = 0;
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char *));
	if (!read(fd, buffer, BUFFER_SIZE) || !buffer)
	{
		free (buffer);
		return (0);
	}
	printf("buffer with size %d = %s\n", BUFFER_SIZE, buffer);
	str = (char *)malloc((get_line_size(buffer) + 1) * sizeof(char *));
	if (buffer[i])
	{
		i = buf_to_str(str, buffer, i);
		return (str);
	}
	i = 0;
	i = buf_to_str(str, buffer, i);
	return (str);
}
