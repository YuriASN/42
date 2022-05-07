/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:19:24 by ysantos-          #+#    #+#             */
/*   Updated: 2022/05/05 01:10:05 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Open failed.\n");
		return (1);
	}
	do
	{
		str = get_next_line(fd);
		printf("%s", str);
	} while (str);
	if (close(fd) == -1)
	{
		printf("Close failed.\n");
		return (1);
	}
	return (0);
}
