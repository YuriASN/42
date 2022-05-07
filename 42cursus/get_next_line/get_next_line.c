/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:59:28 by ysantos-          #+#    #+#             */
/*   Updated: 2022/05/05 04:48:22 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static size_t	get_line_size(char *str)
{
	int		count;

	count = 0;
	while (str[count] || str[count] != '\n')
		++count;
	return (count);
}

/* static size_t	count_str(char *str)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			++count;
		++i;
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
		++o;
	}
	if (buffer[i] == '\n')
	{
		str[o] = buffer[i];
		++i;
	}
	if (!buffer[i])
		i = 0;
	str [o + 1] = '\0';
	return (i);
}

size_t	*read_fd(int fd, char *str)
{
	size_t	x;
	
	x = read(fd, str, BUFFER_SIZE);
	return (x);
}
char	*get_next_line(int fd)
{
	static char		*buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char *));
	char			*str;
	static size_t	i = 0;
	size_t			o;
	//static size_t	nbr_str;

	if (!fd)
		return (0);
	if (!read_fd(fd, buffer))
	{
		free (buffer);
		return (0);
	}
	o = get_line_size(buffer);
	str = (char *)malloc((o + 1) * sizeof(char *));
	i = buf_to_str(str, buffer, i);
	if (i != 0)
	{
		*buffer += i + 1;
		i = 0;
	}
	else if (i == 0 && str[o] != '\n')
	{
		if (!read_fd(fd, buffer))
			return(str);
		i = buf_to_str(&str[o + 1], buffer, i);
	}
	return (str);
}
