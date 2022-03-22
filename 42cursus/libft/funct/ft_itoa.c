/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:35:34 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/22 23:39:03 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns a string representing the integer received as an argument.
Negative numbers must be handled. */

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		++i;
	}
	
}

int	main(void)
{

	return (0);
}
