/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:22:54 by ysantos-          #+#    #+#             */
/*   Updated: 2022/01/27 03:05:00 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int num1, int num2)
{
	char	num1_1;
	char	num1_2;
	char	num2_1;
	char	num2_2;

	num1_1 = (num1 / 10) + '0';
	num1_2 = (num1 % 10) + '0';
	num2_1 = (num2 / 10) + '0';
	num2_2 = (num2 % 10) + '0';
	write (1, &num1_1, 1);
	write (1, &num1_2, 1);
	write (1, " ", 1);
	write (1, &num2_1, 1);
	write (1, &num2_2, 1);
	if (num1 < 98)
	{
		write (1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	num2 = 1;
	while (num1 <= 98)
	{
		while (num2 <= 99)
		{
			ft_print(num1, num2);
			++num2;
		}
		++num1;
		num2 = num1 + 1;
	}
}

/*int	main(void)
{
	ft_print_comb2();
	return (0);
}*/
