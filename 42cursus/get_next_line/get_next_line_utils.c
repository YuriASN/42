/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:17:56 by ysantos-          #+#    #+#             */
/*   Updated: 2022/05/16 02:45:19 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/* Copy buffer to string until \n  is found (return index of buffer after \n).
Or buffer ends (return 0 as index of buffer).*/
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
	{
		i = 0;
	}
	dst[o] = '\0';
	return (i);
}

//Count partial size of line (either until \n or end of string).
size_t	part_size(const char *str)
{
	size_t		count;

	count = 0;
	while (str[count] && str[count] != '\n')
		++count;
	return (count);
}

//count full string size.
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

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
	return (i);
}

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
			return (0);
		}
		++i;
	}
	return (1);
}
