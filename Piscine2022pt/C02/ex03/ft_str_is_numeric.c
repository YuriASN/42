/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:09:38 by ysantos-          #+#    #+#             */
/*   Updated: 2022/01/30 21:32:31 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	value;

	value = 1;
	while (*str)
	{
		if (*str > 47 && *str < 58)
		++str;
		else
		{
			value = 0;
			break ;
		}
	}
	return (value);
}
