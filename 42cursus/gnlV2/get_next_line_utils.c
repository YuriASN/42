/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:00:33 by ysantos-          #+#    #+#             */
/*   Updated: 2022/05/31 23:04:43 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	buf_to_str(char *dst, char *src, size_t i)
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
		++o;
	}
	if (!src[i])
		i = 0;
	dst[o] = '\0';
	return (i);
}

//Free str and set pointer to NULL and return 0 always
void	*free_end(void *str, void *str2)
{
	if (str)
	{
		*str = 0;
		free(str);
		str = 0;
	}
	if (str2)
	{
		*str2 = 0;
		free(str2);
		str2 = 0;
	}
	return (NULL);
}

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

/* Use read and set last byte of string to NULL. Returns same as read
if return is <= 0 it already free the buffer. */
int	read_n_check(int fd, char *str)
{
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

//Allocate buffer size and read fd into it.
char	*get_buffer(int fd)
{
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!buffer || !read_n_check(fd, buffer))
		return (NULL);
}
