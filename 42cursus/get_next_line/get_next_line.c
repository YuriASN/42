/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:59:28 by ysantos-          #+#    #+#             */
/*   Updated: 2022/06/01 22:16:20 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Check if FD given is a binary file.
static int	check_binary(const char *str)
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
			return (1);
		}
		++i;
	}
	return (0);
}

/* Use read and set last byte of string to NULL. Returns same as read
if return is <= 0 it already free the buffer. */
static ssize_t	read_n_check(int fd, char *str, ssize_t *i)
{
	ssize_t	c;

	c = read(fd, str, BUFFER_SIZE);
	if (c <= 0)
	{
		printf("free buffer\t");
		*i = -1;
		free_end(str, NULL);
	}
	str[c] = '\0';
	printf("c: %lu\n", c);
	return (c);
}

//Get the rest of string, until end of file or \n.
static char	*continue_str(int fd, char *str, char *buffer, ssize_t *i)
{
	static char	*str2;
	size_t		a;

	if (read_n_check(fd, buffer, i) <= 0)
		return (str);
	str2 = (char *)malloc(sizeof(char *) * (ft_strlen(str) + 1));
	if (!str2)
		return (free_end(str, buffer));
	a = str_swap(str2, str, 0);
	str = (char *)malloc((a + part_size(buffer) + 1) * sizeof(char *));
	if (!str)
		return (free_end(str2, buffer));
	str_swap(str, str2, 0);
	*i = buf_to_str(&str[ft_strlen(str)], buffer, 0);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	static char		*str;
	static ssize_t	i = BUFFER_SIZE + 1;

	if (i <= BUFFER_SIZE && str)
		free_end(str, NULL);
	if (!fd || BUFFER_SIZE < 1 || i < 0)
	{
		printf("i > BUFFER_SIZE\n");
		i = BUFFER_SIZE + 1;
		return (0);
	}
	if (i > BUFFER_SIZE)
	{
		buffer = (char *) malloc((i) * sizeof(char *));
		if (!buffer || read_n_check(fd, buffer, &i) <= 0)
			return (0);
		i = 0;
	}
	str = (char *)malloc((part_size(&buffer[i]) + 1) * sizeof(char *));
	if (!str)
		return (free_end(buffer, NULL));
	i = buf_to_str(str, buffer, i);
	while (str && i == 0 && str[ft_strlen(str) - 1] != '\n')
		str = continue_str(fd, str, buffer, &i);
	if (i == 0 && str[ft_strlen(str) - 1] == '\n')
		read_n_check(fd, buffer, &i);
	if (check_binary(str))
		return (free_end(str, NULL));
	return (str);
}
