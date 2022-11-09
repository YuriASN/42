/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 12:53:55 by ysantos-          #+#    #+#             */
/*   Updated: 2022/01/30 12:53:57 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write (1, &*str, 1);
		++str;
	}
}
/*
int		main(void)
{
	char str[] = "Hello, world!";
	char *p_str;

	p_str = str;
	ft_putstr(p_str);
}*/