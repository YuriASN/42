/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:31:46 by ysantos-          #+#    #+#             */
/*   Updated: 2022/01/30 12:31:50 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	if (b != 0)
	{
		div = *a / *b;
		mod = *a % *b;
		*a = div;
		*b = mod;
	}
}
/*
int	main(void)
{
	int i = 11;
	int j = 3;
	int *a = &i;
	int *b = &j;

	printf("%d /",i);
	printf(" %d\n",j);

	ft_ultimate_div_mod(a, b);
	
	printf("div (*a) = %d\n",*a);
	printf("mod (*b) = %d",*b);

}*/