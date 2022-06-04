/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:00:30 by ysantos-          #+#    #+#             */
/*   Updated: 2022/05/31 23:06:20 by ysantos-         ###   ########.fr       */
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
			printf("is binary\n");
			return (1);
		}
		++i;
	}
	return (0);
}

//Return the amount of lines in buffer
static size_t	get_lines(const char *buffer)
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

static size_t	continue_str(int fd, char *arr, char *buffer, size_t o)
{
	char	*temp;
	size_t	i;

	temp = (char *)malloc((o + 1) * sizeof(char *));
	if (!temp)
		return (0);
	i = 0;
	while (arr[i])
		temp[i] = arr[i++];
	free_end(arr, NULL);
	o += part_size(buffer);
	arr = (char *)malloc((o + 1) * sizeof(char *));
	if (!arr)
		return (0);
	i = 0;
	while (temp[i])
		arr[i] = temp[i++];
	free_end(temp, NULL);
	i = buf_to_str(arr, buffer, i);
	return (i);
}

/* Copy buffer to arr until end of buffer is found,
free buffer and return 0 if any error occurs */
static int	buf_to_arr(int fd, char **arr, char *buffer)
{
	size_t	str;
	size_t	i;
	size_t	o;

	str = 0;
	i = 0;
	while (buffer[i])
	{
		o = part_size(&buffer[i]);
		arr[str] = (char *)malloc((o + 1) * sizeof(char *));
		if (!arr[str])
			return (0);
		i = buf_to_str(*arr[str], buffer, i);
		while (i == 0 && arr[0][part_size(&arr[str]) - 1] != '\n')
		{
			if (!read_n_check(fd, buffer))
				return (1);
			i = continue_str(fd, &arr[0], buffer, o);
		}
		printf("|%s|\n", arr[str]);
		++str;
	}
	arr[str] = NULL;
	free_end(buffer; NULL);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	**arr;
	char		*buffer;

	printf("in |");
	if (!fd || BUFFER_SIZE < 1)
		return (0);
	if (arr[0] && !arr[1])
		free_end(arr, NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!buffer || !read_n_check(fd, buffer))
		return (NULL);
	if (!arr)
		arr = (char **)malloc((get_lines(buffer) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!buf_to_arr(fd, arr, buffer))
		return (NULL);
	if (check_binary(*arr))
		return (NULL);
	return (*arr);
}
