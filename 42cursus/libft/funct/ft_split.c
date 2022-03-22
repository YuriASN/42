/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:38:58 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/22 23:34:42 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Returns an array of strings obtained by splitting ’s’
using the character ’c’ as a delimiter.
The array must end with a NULL pointer. */

#include "libft.h"

static size_t	count_strings(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		++i;
	while (s[i])
	{
		if (s[i] == c)
		{
			++count;
			while (s[i] == c && s[i + 1])
				++i;
		}
		++i;
	}
	if (s[i - 1] != c && !s[i])
		++count;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	str;
	size_t	i;
	size_t	save;

	arr = (char **)malloc(count_strings(s, c) * sizeof(char *));
	if (!arr || !s || !c)
		return (0);
	str = 0;
	i = 0;
	while (str < count_strings(s, c))
	{
		while (s[i] == c)
			++i;
		save = i;
		while (s[i] != c)
			i++;
		arr[str] = ft_substr(s, save, (i - save));
		++str;
	}
	return (arr);
}

/* int	main(void)
{
	char	*str;
	char	**result;
	int		nbr;
	int		i;

	str = "Hello, people,,,, from this nice,,,,, world.";
	nbr = count_strings(str, ',');
	printf("%d\n", nbr);
	result = ft_split(str, ',');
	for(i = 0; i < nbr; ++i)
	{
		printf("String n %d = %s\n", i, result[i]);
	}
	return (0);
} */
