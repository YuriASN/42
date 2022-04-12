/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:59:28 by ysantos-          #+#    #+#             */
/*   Updated: 2022/04/12 16:36:52 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buffer;
	size_t			buffer_size;
	static size_t	pos;

	if (!fd)
		return (0);
	pos = 0;
	lseek(fd, pos, SEEK_SET);
	buffer_size = get_line_size(fd);
	buffer = (char *)malloc(buffer_size + 1 * sizeof(char *));
	read(fd, buffer, buffer_size);
	pos += buffer_size;
	return (buffer);
}
