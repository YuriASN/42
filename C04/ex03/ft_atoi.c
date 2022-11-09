/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:22:32 by joacorre          #+#    #+#             */
/*   Updated: 2022/02/03 05:30:11 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_atoi(char *str)
{
	int	a;
	int	rst;
	int	pn;

	a = 0;
	rst = 0;
	pn = 1;
	while ((str[a] >= '\t' && str[a] <= '\r') || (str[a] == ' '))
	{
		a++;
	}
	while (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
		{
			pn *= -1;
		}
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		rst = ((rst * 10) + (str[a] - '0'));
		a++;
	}
	return (rst * pn);
}

/* int main()
{
	char a[] = " 	\v\r--+---+12455345abc567";
	printf("%d", ft_atoi(a));

	return 0;
} */