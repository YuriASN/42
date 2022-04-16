/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:59:28 by ysantos-          #+#    #+#             */
/*   Updated: 2022/04/16 22:52:35 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_ptr(char *str, char *buffer)
{
	free(str);
	free(buffer);
}

static size_t	get_line_size(int fd)
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
}

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

	i = 0;
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char *));
	str = (char *)malloc((get_line_size(fd) + 1) * sizeof(char *));
	if (!str || !buffer || !fd)
	{
		free_ptr(str, buffer);
		return (0);
	}
	if (buffer[i])
	{
		i = buf_to_str(str, buffer, i);
		return (str);
	}
	if (!read(fd, buffer, BUFFER_SIZE))
	{
		free_ptr(str, buffer);
		return (0);
	}
	i = 0;
	i = buf_to_str(str, buffer, i);
	return (str);
}
