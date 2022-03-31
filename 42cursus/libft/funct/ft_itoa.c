/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:35:34 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/31 01:03:34 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns a string representing the integer received as an argument.
Negative numbers must be handled. */

static int	ft_size(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		++i;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	swap_nbr(int x, char *str)
{
	static int	i;

	i = 0;
	if (x > 0)
	{
		swap_nbr(x / 10, str);
		str[i++] = (x % 10) + '0';
	}
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * ft_size(n) + 1);
	if (!str)
		return (0);
	i = 0;
	if (n == 0)
		str[0] = '0';
	if (n == -2147483648)
	{
		str = "-2147483648";
		str[ft_strlen(str)] = '\0';
		return (str);
	}
	if (n < 0)
	{
		str[i] = '-';
		n *= -1;
		++i;
	}
	swap_nbr(n, &str[i]);
	str[ft_strlen(str)] = '\0';
	return (str);
}

/* int	main(void)
{
	char	*a;
	int		x;

	x = 0;
	a = ft_itoa(x);
	printf("Numero: %d\nStrg: %s\n\n", x, a);
	x = -5859;
	a = ft_itoa(x);
	printf("Numero: %d\nStrg: %s\n\n", x, a);
	x = -1234;
	a = ft_itoa(x);
	printf("Numero: %d\nStrg: %s\n\n", x, a);
	return (0);
} */
