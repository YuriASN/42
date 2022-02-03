/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:53:43 by ysantos-          #+#    #+#             */
/*   Updated: 2022/01/30 21:56:29 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	value;

	value = 1;
	while (*str)
	{
		if (*str > 64 && *str < 91)
		++str;
		else
		{
			value = 0;
			break ;
		}
	}
	return (value);
}
