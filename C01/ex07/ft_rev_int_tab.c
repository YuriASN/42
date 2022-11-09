/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 13:09:53 by ysantos-          #+#    #+#             */
/*   Updated: 2022/01/30 13:09:56 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	curr;

	curr = 0;
	while (curr < size)
	{
		temp = tab[curr];
		tab[curr] = tab[size - 1];
		tab[size - 1] = temp;
		++curr;
		--size;
	}
}
/*
void putarr(int arr[], int size)
{
    for (int i = 0; i < (size -1); i++)
        printf("%d, ", arr[i]);
    printf("%d\n", arr[size - 1]);
}

int		main (void)
{
	int tab[] = {1, 3, 2, 4};
	int size;
	
	size = 4;

	printf("Original: ");
	putarr(tab, size);

	ft_rev_int_tab(tab, size);

	printf("Modified: ");
	putarr(tab, size);
}*/