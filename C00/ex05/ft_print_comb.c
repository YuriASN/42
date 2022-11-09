/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:22:05 by ysantos-          #+#    #+#             */
/*   Updated: 2022/01/27 21:40:23 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printchar(char a, char b, char c)
{
	write (1, &a, 1);
	write (1, &b, 1);
	write (1, &c, 1);
	if (a < '7')
	{
		write (1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = '0';
	num2 = '1';
	num3 = '2';
	while (num1 <= '7')
	{
		while (num2 <= '9')
		{
			while (num3 <= '9')
			{
				ft_printchar(num1, num2, num3++);
			}
			++num2;
			num3 = num2 + 1;
		}
		++num1;
		num2 = num1 + 1;
		num3 = num2 + 1;
	}
}

/*int main(void)
{
	ft_print_comb();
	return (0);
}*/
