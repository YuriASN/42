/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:59:28 by ysantos-          #+#    #+#             */
/*   Updated: 2022/05/08 01:46:32 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static size_t	line_size(const char *str)
{
	size_t		count;

	count = 0;
	while (str[count] && str[count] != '\n')
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

//Copy src to dst and return final size of dst.
size_t	ft_strlcpy(char *dst, const char *src, size_t src_start)
{
	size_t	i;

	i = 0;
	while (src[src_start])
	{
		dst[i] = src[src_start];
		++i;
		++src_start;
	}
	dst[i] = '\0';
	return ((size_t)line_size(dst));
}

static size_t	buf_to_str(char *dst, const char *src, size_t i)
{
	size_t	o;

	o = 0;
	while (src[i] != '\n' && src[i])
	{
		dst[o] = src[i];
		++i;
		++o;
	}
	if (src[i] == '\n')
	{
		dst[o] = src[i];
		++i;
	}
	if (!src[i])
		i = 0;
	dst[o + 1] = '\0';
	return (i);
}

ssize_t	read_fd(int fd, char *str)
{
	ssize_t	x;

	x = read(fd, str, BUFFER_SIZE);
	//printf("\e[0;34mread = %s \n\e[0;37m", str);
	return (x);
}

size_t	buffer_end(size_t i, char *str)
{
	if (i != 0)
	{
		*str += i + 1;
		i = 0;
	}
	return (i);
}


char	*get_next_line(int fd)
{
	static char		*buffer;
	static char		*str;
	static char		*str2;
	static size_t	i = 0;
	ssize_t			o;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!fd || !buffer)
		return (0);
	if (str)
		free (str);
	if (!buffer[0])
	{
		o = read_fd(fd, buffer);
		if (o < 1)
		{
			free (buffer);
			return (0);
		}
	}
	o = line_size(buffer);
	str = (char *)malloc((o + 1) * sizeof(char *));
	if (!str)
		return (0);
	i = buf_to_str(str, buffer, i);
	//printf("\nbuffer = %s\tstr = %s\n", buffer, str);
	i = buffer_end(i, buffer);
	while (i == 0 && str[o] != '\n')
	{
		o = read_fd(fd, buffer);
		//printf("2buffer = %s\tstr = %s\n", buffer, str);
		if (o < 1)
		{
			//printf("\nif do while\t\tstr = %s\n", str);
			free (buffer);
			return (str);
		}
		str2 = (char *)malloc((line_size(str)) * sizeof(char *));
		if (!str2)
		{
			//printf("\n\n\t\t\t\tERROR str2\n\n\n");
			free (buffer);
			return (str);
		}
		ft_strlcpy(str2, str, 0);
		free (str);
		str = (char *)malloc(sizeof(char *) * (o + line_size(str2) + 1));
		o = ft_strlcpy(str, str2, 0);
		i = buf_to_str(&str[o], buffer, 0);
		i = buffer_end(i, buffer);
		//printf("BUffer = %s\n", buffer);
		o = line_size(str);
		//printf("3buffer = %s\tstr = %s\n", buffer, str);
	}
/* 	else if (i == 0 && str[o] != '\n')
	{
		while (str[o] != '\n')
		{
			o = read_fd(fd, buffer);
	//printf("2buffer = %s\tstr = %s\n", buffer, str);
			if (o < 1)
			{
				//printf("\nif do while\n");
				free (buffer);
				return (str);
			}
			str2 = (char *)malloc((line_size(str)) * sizeof(char *));
			if (!str2)
			{
				//printf("\n\n\t\t\t\tERROR str2\n\n\n");
				free (buffer);
				return (str);
			}
			ft_strlcpy(str2, str, 0);
			free (str);
			str = (char *)malloc(sizeof(char *) * (o + line_size(str2) + 1));
			ft_strlcpy(str, str2, 0);
			i = buf_to_str(&str[o], buffer, 0);
			o = line_size(str);
	//printf("3buffer = %s\tstr = %s\n", buffer, str);
		}
	} */
	return (str);
}
