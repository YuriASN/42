/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:19:24 by ysantos-          #+#    #+#             */
/*   Updated: 2022/05/08 01:28:44 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*str;
	size_t	i = 0;

	fd1 = open("text.txt", O_RDONLY);
	if (fd1 == -1)
	{
		printf("Open 1 failed.\n");
		return (1);
	}

	fd2 = open("a.out", O_RDONLY);
	if (fd2 == -1)
	{
		printf("Open 2 failed.\n");
		return (1);
	}

	do
	{
		str = get_next_line(fd1);
		if (str)
		{
			printf("\e[0;31mMAIN = |%s|\e[0;37m", str);
			getchar ();
		}
	} while (str);
	free (str);

	printf("\nEnd of text file ---------------- Start of binary a.out\n\n");

	do
	{
		str = get_next_line(fd2);
		if (str)
		{
			printf("\e[0;31mMAIN = |%s|\e[0;37m", str);
			while (str[i])
			{
				printf("|%c| = |%i|\t", str[i], str[i]);
				++i;
			}
			getchar ();
		}
	} while (str);
	free (str);
	
	if (close(fd1) == -1)
	{
		printf("Close 1 failed.\n");
		return (1);
	}
	if (close(fd2) == -1)
	{
		printf("Close 2 failed.\n");
		return (1);
	}
	return (0);
}
