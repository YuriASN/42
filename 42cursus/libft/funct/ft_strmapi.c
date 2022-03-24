/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:28:54 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/24 21:44:00 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Applies the function 'f' to each char of the string 's',
and passing its index as 1st argument to create a new string (with malloc)
resulting from sucessive appliacctions of 'f'.
Returns the string created from sucessive 'f' apllications.*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	str = (char *)malloc(ft_strlen(s) + 1);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		++i;
	}
	return (str);
}
