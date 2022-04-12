/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:17:56 by ysantos-          #+#    #+#             */
/*   Updated: 2022/04/12 18:03:04 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_line_size(int fd)
{
	int		count;
	char	c;

	count = 0;
	while (c != '\n' || fd)
	{
		read(fd, &c, 1);
		++count;
		lseek(fd, 1, SEEK_CUR);
	}
	return (count);
}
