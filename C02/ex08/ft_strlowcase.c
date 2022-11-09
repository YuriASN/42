/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:45:11 by ysantos-          #+#    #+#             */
/*   Updated: 2022/01/31 20:37:20 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
		{
			str[index] += 32;
		}
		++index;
	}
	return (str);
}
/* 
int		main(void)
{
	char	str_base[] = "HELl0 noOb, we'RE sinKINg 2geTher.";

	printf("Before		: %s\n", str_base);
	ft_strlowcase(str_base);
	printf("After		: %s\n", str_base);
} */
