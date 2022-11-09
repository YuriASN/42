/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcombn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:38:41 by ysantos-          #+#    #+#             */
/*   Updated: 2022/01/28 02:03:39 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printcomb(int n, int print[])
{
	int		a;
	char	x;

	a = 0;
	while (a < n)
	{
		x = print[a] + '0';
		write(1, &x, 1);
		++a;
	}
	if (print[0] != 10 - n)
	{
		write (1, ", ", 2);
	}
}

void	getcomb8(int n, int nbrs[])
{
	nbrs[7] = nbrs[6] + 1;
	while (nbrs[7] <= 9)
	{
		if (n == 8)
		{
			printcomb(n, nbrs);
		}
		else
		{
			nbrs[8] = nbrs[7] + 1;
			while (nbrs[8] <= 9)
			{
				printcomb(n, nbrs);
				++nbrs[8];
			}
		}
		++nbrs[7];
	}
}

void	getcomb6(int n, int nbrs[])
{
	nbrs[5] = nbrs[4] + 1;
	while (nbrs[5] <= 9)
	{
		if (n == 6)
		{
			printcomb(n, nbrs);
		}
		else
		{
			nbrs[6] = nbrs[5] + 1;
			while (nbrs[6] <= 9)
			{
				if (n == 7)
				{
					printcomb(n, nbrs);
				}
				else
				{
					getcomb8(n, nbrs);
				}
				++nbrs[6];
			}
		}
		++nbrs[5];
	}
}

void	getcomb4(int n, int nbrs[])
{
	nbrs[3] = nbrs[2] + 1;
	while (nbrs[3] <= 9)
	{
		if (n == 4)
		{
			printcomb(n, nbrs);
		}
		else
		{
			nbrs[4] = nbrs[3] + 1;
			while (nbrs[4] <= 9)
			{
				if (n == 5)
				{
					printcomb(n, nbrs);
				}
				else
				{
					getcomb6(n, nbrs);
				}
				++nbrs[4];
			}
		}
		++nbrs[3];
	}
}

void	getcomb2(int n, int nbrs[])
{
	if (n == 2)
	{
		printcomb(n, nbrs);
	}
	else
	{
		nbrs[2] = nbrs[1] + 1;
		while (nbrs[2] <= 9)
		{
			if (n == 3)
			{
				printcomb(n, nbrs);
			}
			else
			{
				getcomb4(n, nbrs);
			}
			++nbrs[2];
		}
	}
	++nbrs[1];
}

void	ft_print_combn(int n)
{
	int	nbrs[9];

	nbrs[0] = 0;
	if (n <= 1 || n >= 10)
	{
		write (1, "Number isn't on the combination range!", 38);
	}
	else
	{
		while (nbrs[0] <= 10 - n)
		{
			nbrs[1] = nbrs[0] + 1;
			while (nbrs[1] <= 9)
			{
				getcomb2(n, nbrs);
			}
			++nbrs[0];
		}
	}
}
/*
int	main(void)
{
	int	x;

	x = 5;
	ft_print_combn(x);
	return (0);
}*/
