/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:00:33 by ysantos-          #+#    #+#             */
/*   Updated: 2022/05/30 19:51:06 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Count partial size of string (either until \n or end of string).
size_t	part_size(const char *str)
{
	size_t		count;

	count = 0;
	while (str[count] && str[count] != '\n')
		++count;
	if (str[count] == '\n')
			++count;
	return (count);
}

/* Copy buffer to arr until end of buffer is found,
free buffer and return 0 if any error occurs */
int	buf_to_arr(char **arr, char *buffer)
{
	size_t	str;
	size_t	i;
	size_t	o;
	size_t	u;

	str = 0;
	i = 0;
	while (buffer[i])
	{
		o = part_size(&buffer[i]);
		arr[str] = (char *)malloc((o + 1) * sizeof(char *));
		if (!arr[str])
			return (0);
		arr[str][o] = '\0';
		u = 0;
		while (u < o)
		{
			arr[str][u++] = buffer[i++];			//++ depois?
		}
		printf("|%s|\n", arr[str]);
		++str;
	}
	arr[str] = NULL;
	free (buffer);
	buffer = NULL;
	return (1);
}

//Check if FD given is a binary file.
int	check_binary(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		{
			++i;
			continue ;
		}
		else if ((str[i] < 31 && str[i] > 1) || str[i] == 127)
		{
			printf("is binary\n");
			return (1);
		}
		++i;
	}
	return (0);
}

/* Use read and set last byte of string to NULL. Returns same as read
if return is <= 0 it already free the buffer. */
int	read_n_check(int fd, char *str)
{
	printf("read |\t");
	ssize_t	c;

	c = read(fd, str, BUFFER_SIZE);
	if (c <= 0)
	{
		free (str);
		str = NULL;
		return (0);
	}
	str[c] = '\0';
	return (1);
}

//Return the amount of lines in buffer
size_t	get_lines(const char *buffer)
{
	size_t	i;
	size_t	strings;

	strings = 1;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n' && buffer[i + 1])
			++strings;
		++i;
	}
	return (strings);
}

//count full string size.
/* size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
} */