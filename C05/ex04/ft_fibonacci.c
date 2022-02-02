/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:22:17 by marvin            #+#    #+#             */
/*   Updated: 2022/02/02 17:22:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_fibonacci(int index)
{
	int prev;
	int	max;

	max = 9 - index;
	prev = index - 1;
	if (index < 0)
		return (-1);
	if (index == 0)
		{
			index = 1;
			--max;
		}
	else if (max > 0)
	{
		printf("max = %d\n", max);
		ft_fibonacci(index++);
		index += prev;
	}
	return (index);
}

int	main(void)
{
	int	index;

	index = -2;
	while (index < 16)
	{
		printf("fibonacci(%d) = %d\n", index, ft_fibonacci(index));
		index++;
	}
}