/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 23:49:37 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/13 22:26:08 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/*
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = (char *)malloc(ft_strlen(s1) + 1);
	if (newstr == NULL)
		return (0);
	while (s1[i] == set[0])
		++i;
	j = ft_strlen(&s1[i]) - 1;
	while (s1[j + i] == set[0])
		--j;
	ft_strlcpy(newstr, &s1[i], j + 2);
	return (newstr);
}

/* int	main(void)
{
	char	*str = "---Essa e' a str anteri-or.--";
	char	*set = "-";

	printf("A str antiga e': %s\nA str nova e': %s\n", str, ft_strtrim(str, set));
	return (0);
} */
