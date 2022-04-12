/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:19:24 by ysantos-          #+#    #+#             */
/*   Updated: 2022/04/12 18:27:46 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Open failed.\n");
		return (1);
	}
	while (get_next_line(fd))
		printf("%s", get_next_line(fd));
	if (close(fd) == -1)
	{
		printf("Close failed.\n");
		return (1);
	}
	return (0);
}
