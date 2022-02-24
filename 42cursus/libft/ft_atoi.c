/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:43:11 by ysantos-          #+#    #+#             */
/*   Updated: 2022/02/24 21:43:11 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;
	int	index;

	index = 0;
	nbr = 0;
	sign = 1;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-' )
			sign *= -1;
		++index;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		nbr *= 10;
		nbr += str[index] - '0';
		++index;
	}
	return (nbr * sign);
}
