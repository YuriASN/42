/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:00:30 by ysantos-          #+#    #+#             */
/*   Updated: 2022/05/30 19:51:01 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	**arr;
	char		*buffer;

	printf("in |");
	if (arr[0])
	{
		++*arr;
		if (*arr == NULL)
		{
			free (arr);
			return (0);
		}
		return (*arr);
	}
	if (!fd || BUFFER_SIZE < 1)
		return (0);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!buffer || !read_n_check(fd, buffer))
		return (0);
	arr = (char **)malloc((get_lines(buffer) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	if (!buf_to_arr(arr, buffer))
		return (0);
	if (check_binary(*arr))
		return (0);
	return (*arr);
}
