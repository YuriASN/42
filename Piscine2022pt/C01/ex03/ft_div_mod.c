/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:30:00 by ysantos-          #+#    #+#             */
/*   Updated: 2022/01/30 12:30:04 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int*mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}
/*
int	main(void)
{
	int	a = 11;
	int b = 3;
	int c;
	int d;

	ft_div_mod(a, b, &c, &d);
	printf ("div = %i. mod = %i.\n", c, d);
	return (0);
}*/
