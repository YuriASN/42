/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 05:43:46 by marvin            #+#    #+#             */
/*   Updated: 2022/02/03 05:39:42 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strl(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		++size;
	return (size);
}

int	ft_checkbase(char *base, int size)
{
	int	index;
	int	next;

	index = 0;
	next = 1;
	while (base[index + 1])
	{
		while (next != size - 1)
		{
			if (base[index] == base[next])
				return (0);
			++next;
		}
		++index;
		next = index + 1;
	}
	while (*base)
	{
		if (*base == '+' || *base == '-' || *base == ' ' || *base == '\t')
			return (0);
		if (*base == '\r' || *base == '\n' || *base == '\v' || *base == '\f')
			return (0);
		++base;
	}
	return (1);
}

int	ft_swaptonbr(char *str, char *base, int size)
{
	int	swap;
	int	nbr;
	int	minus;

	nbr = 0;
	minus = 1;
	while (*str)
	{
		swap = 0;
		if (*str == '-')
			minus *= -1;
		while (swap < size)
		{
			if (*str == base[swap])
			{
				nbr *= size;
				nbr += swap;
			}
			++swap;
		}
		++str;
	}
	return (nbr * minus);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	base_size;

	result = 0;
	base_size = ft_strl(base);
	if (base_size <= 1)
		return (0);
	if (ft_checkbase(base, base_size) == 1)
	{
		result = ft_swaptonbr(str, base, base_size);
	}
	return (result);
}

/* int	main(void)
{
	printf("%d\n", ft_atoi_base("11110001001000000", "01"));
	fflush(stdout);
	printf("%d\n", ft_atoi_base("-1e240", "0123456789abcdef"));
	fflush(stdout);
	printf("%d\n", ft_atoi_base("----420", "01234567"));
	fflush(stdout);
} */