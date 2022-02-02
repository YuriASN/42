/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 05:43:46 by marvin            #+#    #+#             */
/*   Updated: 2022/02/02 05:43:46 by marvin           ###   ########.fr       */
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
	if (size <= 1)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-' || *base == ' ')
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
	if (ft_checkbase(base, base_size) == 1)
	{
		result = ft_swaptonbr(str, base, base_size);
	}
	return (result);
}

/*int	main(void)
{
	printf("%d\n", ft_atoi_base("11110001001000000", "01"));
	fflush(stdout);
	printf("%d\n", ft_atoi_base("-1e240", "0123456789abcdef"));
	fflush(stdout);
	printf("%d\n", ft_atoi_base("-123456", "0123456789"));
	fflush(stdout);
}*/