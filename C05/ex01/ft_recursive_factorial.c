/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:42:22 by marvin            #+#    #+#             */
/*   Updated: 2022/02/02 13:42:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_factorial(int nb, int value)
{
	value *= nb--;
	if (nb > 1)
		return (ft_factorial(nb, value));
	return (value);
}

int	ft_recursive_factorial(int nb)
{
	int	factorial;

	factorial = 1;
	if (nb < 1 || nb > 12)
		return (0);
	else
		return (ft_factorial(nb, factorial));
}

/* int	main(void)
{
	int n;

	n = -2;
	while (n < 7)
	{
		printf("fact(%d) = %d\n", n, ft_recursive_factorial(n));
		n++;
	}
} */