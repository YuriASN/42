/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:57:48 by ysantos-          #+#    #+#             */
/*   Updated: 2022/01/31 03:22:46 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	value;

	value = 1;
	while (*str)
	{
		if (*str < 32 || *str > 126)
		{
			value = 0;
			break ;
		}
		else
		++str;
	}
	return (value);
}
