/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:13:10 by marvin            #+#    #+#             */
/*   Updated: 2022/02/02 03:13:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	nbr;
	int	minus;

	nbr = 0;
	minus = 1;
	while (*str)
	{
		if (*str == '-')
		{
			minus *= -1;
			++str;
		}
		if (*str > '0' && *str < '9')
		{
			while (*str > '0' && *str < '9')
			{
				nbr *= 10;
				nbr += *str - '0';
				++str;
			}
			return (nbr * minus);
		}
		++str;
	}
	return (0);
}

/* int		main(void)
{
	char *str;

	str = " ---+--+1234ab567";
	printf("%d\n", ft_atoi(str));
} */