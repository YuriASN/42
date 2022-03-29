/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:43:11 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/29 23:15:56 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function returns the converted integral number as an int value.
If no valid conversion could be performed, it returns zero. */

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;
	int	i;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' )
			sign *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - '0';
		++i;
	}
	return (nbr * sign);
}

/* int	main(void)
{
	int		val;
	char	str[20] = "98993489as";
	char	str1[20] = "profile.intra.42.fr";

	val = ft_atoi(str);
	printf("String value = %s, Int value = %d\n", str, val);
	val = atoi(str1);
	printf("String value = %s, Int value = %d\n", str1, val);
	return (0);
} */
