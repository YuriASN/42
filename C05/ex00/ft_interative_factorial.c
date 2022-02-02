/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interative_factorial.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:18:18 by marvin            #+#    #+#             */
/*   Updated: 2022/02/02 13:18:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	value;

	value = 1;
	if (nb < 1 || nb > 12)
		return (0);
	while (nb > 1)
	{
		value *= nb;
		--nb;
	}
	return (value);
}

/* int	main(void)
{
	int n;

	n = -2;
	while (n < 15)
	{
		printf("fact(%d) = %d\n", n, ft_iterative_factorial(n));
		n++;
	}
} */