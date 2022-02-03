/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:34:00 by ysantos-          #+#    #+#             */
/*   Updated: 2022/01/30 21:53:05 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	value;

	value = 1;
	while (*str)
	{
		if (*str > 96 && *str < 123)
		++str;
		else
		{
			value = 0;
			break ;
		}
	}
	return (value);
}
