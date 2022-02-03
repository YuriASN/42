/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:21:02 by ysantos-          #+#    #+#             */
/*   Updated: 2022/01/31 03:04:12 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	value;

	value = 1;
	while (*str)
	{
		if (*str > 64 && *str < 91)
		++str;
		else if (*str > 96 && *str < 123)
		++str;
		else
		{
			value = 0;
			break ;
		}
	}
	return (value);
}
