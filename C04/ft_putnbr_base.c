/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:38:50 by marvin            #+#    #+#             */
/*   Updated: 2022/02/02 03:38:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_printchar(char c)
{
	write (1, &c, 1);
}

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
		if (*base == '+' || *base == '-')
			return (0);
		++base;
	}
	return (1);
}

void	ft_swapnbr(int nbr, char *base, int size)
{
	if (nbr >= size)
	{
		ft_swapnbr(nbr / size, base, size);
		ft_swapnbr(nbr % size, base, size);
	}
	else
		ft_printchar(base[nbr]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_size;

	base_size = ft_strl(base);
	if (ft_checkbase(base, base_size) == 1)
	{
		if (nbr < 0)
		{
			write (1, "-", 1);
			nbr *= -1;
		}
		ft_swapnbr(nbr, base, base_size);
	}
}

/* int	main(void)
{
	ft_putnbr_base(-123456, "helo");
	printf("\n");
	fflush(stdout);
	ft_putnbr_base(684843858, "jufrscx");
	printf("\n");
	fflush(stdout);
	ft_putnbr_base(38581613, "kkrex");
	printf("\n");
	fflush(stdout);
	ft_putnbr_base(38581613, "kk-rex");
	return (0);
} */