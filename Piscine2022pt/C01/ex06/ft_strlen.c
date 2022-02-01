/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 13:01:19 by ysantos-          #+#    #+#             */
/*   Updated: 2022/01/30 13:01:22 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	value;

	value = 0;
	while (*str != '\0')
	{
		++value;
		++str;
	}
	return (value);
}
/*
int	main (void)
{
	char str[] = "Amanda";

	int count = ft_strlen(str);
	
	printf("%d\n", count);
}*/