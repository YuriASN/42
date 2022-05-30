/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:57:55 by ysantos-          #+#    #+#             */
/*   Updated: 2022/05/18 22:57:55 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_all(int fd)
{
	char	*str;

	do
	{
		str = get_next_line(fd);
		if (str)
		{
			printf("\e[0;31mMAIN = |%s|\e[0;37m\n", str);
			getchar ();
		}
	} while (str);
}

int	main(void)
{
	int		fd[16];
	//int		byn;
	int		i;

	fd[0] = open("text.txt", O_RDONLY);
	fd[1] = open("42cursus/get_next_line/gnlTester/files/41_no_nl", O_RDONLY);
	fd[2] = open("42cursus/get_next_line/gnlTester/files/41_with_nl", O_RDONLY);
	fd[3] = open("42cursus/get_next_line/gnlTester/files/42_no_nl", O_RDONLY);
	fd[4] = open("42cursus/get_next_line/gnlTester/files/42_with_nl", O_RDONLY);
	fd[5] = open("42cursus/get_next_line/gnlTester/files/43_no_nl", O_RDONLY);
	fd[6] = open("42cursus/get_next_line/gnlTester/files/43_with_nl", O_RDONLY);
	fd[7] = open("42cursus/get_next_line/gnlTester/files/alternate_line_nl_no_nl", O_RDONLY);
	fd[8] = open("42cursus/get_next_line/gnlTester/files/alternate_line_nl_with_nl", O_RDONLY);
	fd[9] = open("42cursus/get_next_line/gnlTester/files/big_line_no_nl", O_RDONLY);
	fd[10] = open("42cursus/get_next_line/gnlTester/files/big_line_with_nl", O_RDONLY);
	fd[11] = open("42cursus/get_next_line/gnlTester/files/empty", O_RDONLY);
	fd[12] = open("42cursus/get_next_line/gnlTester/files/multiple_line_no_nl", O_RDONLY);
	fd[13] = open("42cursus/get_next_line/gnlTester/files/multiple_line_with_nl", O_RDONLY);
	fd[14] = open("42cursus/get_next_line/gnlTester/files/multiple_nlx5", O_RDONLY);
	fd[15] = open("42cursus/get_next_line/gnlTester/files/nl", O_RDONLY);

	for (i = 0; i < 17; ++i)
	{
		printf("\e[4;33mFD%i\e[0m\n", i);
		if (fd[i] == -1)
		{
			printf("Open fd%i failed.\n", i);
			return (1);
		}
		read_all(fd[i]);
		if (close(fd[i]) == -1)
		{
			printf("Close fd%i failed.\n", i);
			return (1);
		}
	}
	/* byn = open("a.out", O_RDONLY);
	if (byn == -1)
	{
		printf("Open 2 failed.\n");
		return (1);
	}
	read_all(byn);
	for (i = 0; i < 16; ++i)
	{
		if (close(fd[i]) == -1)
		{
			printf("Close fd%i failed.\n", i);
			return (1);
		}
	}
	if (close(byn) == -1)
	{
		printf("Close byn failed.\n");
		return (1);
	} */
	return (0);
}
