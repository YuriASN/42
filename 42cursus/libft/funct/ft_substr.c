/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:00:22 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/13 22:04:04 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ (bit x) and is of
maximum size ’len’.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	sub = (char *)malloc(len + 1);
	if (!sub)
		return (0);
	if (!s || start > (unsigned int)ft_strlen(s) || len == 0)
	{
		sub[0] = '\0';
		return (sub);
	}
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}

/* int	main(void)
{
	char	*a = "String to be copied from here until here and not reach the end";
	char	*b;

	b = ft_substr(a, 25, 150);
	printf("Str: %s\nSubstr:%s\n", a, b);
	return (0);
} */
