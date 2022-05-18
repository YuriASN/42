/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:59:28 by ysantos-          #+#    #+#             */
/*   Updated: 2022/05/18 22:41:08 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Free str and set pointer to NULL and return 0 always
static void	*free_end(char *str, char *str2)
{
	if (str)
	{
		free(str);
		*str = 0;
	}
	if (str2)
	{
		free (str2);
		*str2 = 0;
	}
	return (0);
}

//Get the rest of string, until end of file or \n.
static char	*continue_str(int fd, char *str, char *buffer, ssize_t *i)
{
	static char	*str2;
	size_t		a;

	*i = read(fd, buffer, BUFFER_SIZE);
	if (*i <= 0)
	{
		*i = -1;
		free_end (buffer, NULL);
		return (str);
	}
	buffer[*i] = '\0';
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

/* Use read and set last byte of string to NULL. Returns same as read
if return is <= 0 it already free the buffer. */
static ssize_t	read_n_check(int fd, char *str)
{
	ssize_t	c;

	c = read(fd, str, BUFFER_SIZE);
	if (c <= 0)
		free_end(str, NULL);
	str[c] = '\0';
	return (c);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	static char		*str;
	static ssize_t	i = 0;

	if (str)
		free (str);
	if (!fd || BUFFER_SIZE < 1 || i < 0)
		return (0);
	if (i == 0)
	{
		buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char *));
		if (!buffer)
			return (0);
		if (!read_n_check(fd, buffer))
			return (0);
	}
	str = (char *)malloc((part_size(buffer) + 1) * sizeof(char *));
	if (!str)
		return (free_end(buffer, NULL));
	i = buf_to_str(str, buffer, i);
	if (!check_binary(buffer))
		return (free_end(str, buffer));
	while (str && i == 0 && str[ft_strlen(str) - 1] != '\n')
		str = continue_str(fd, str, buffer, &i);
	return (str);
}
