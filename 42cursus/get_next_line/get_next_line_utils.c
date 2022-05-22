/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:17:56 by ysantos-          #+#    #+#             */
/*   Updated: 2022/05/23 00:36:18 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Copy buffer to string until \n  is found (return index of buffer after \n)
or buffer ends (return 0 as index of buffer).*/
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

//Count partial size of string (either until \n or end of string).
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

//Copy src to dst and return final size of dst, and free src.
size_t	str_swap(char *dst, char *src, size_t src_start)
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
	free_end(src, NULL);
	return (i);
}

//Free str and set pointer to NULL and return 0 always
void	*free_end(char *str, char *str2)
{
	if (str)
	{
		printf("\e[0;36mstr1 to free = |%s|\e[0m\n", str);
		free(str);
		*str = 0;
		if (str == NULL)
			printf("YES\n");
	}
	if (str2)
	{
		printf("\e[0;36mstr2 to free = |%s|\e[0m\n", str2);
		free(str2);
		*str2 = 0;
	}
	return (NULL);
}