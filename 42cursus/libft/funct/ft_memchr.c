/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:31:43 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/13 18:22:50 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* searches for the FIRST occurrence of the character c (an unsigned char)
in the first n bytes of the string pointed to, by the argument str.
This function returns a pointer to the matching byte
or NULL if the character does not occur in the given memory area. */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t bytes)
{
	size_t	index;

	index = 0;
	while (index < bytes && ((unsigned char *)str)[index] != '\0')
	{
		if (((unsigned char *)str)[index] == (unsigned char)c)
			return ((void *)(str + index));
		index++;
	}
	return (0);
}

/* int	main(void)
{
	const char	str[] = "https://profile.intra.42.fr/";
	const char	ch = 'i';
	char		*ret;

	ret = ft_memchr(str, ch, ft_strlen(str));
	printf("String after |%c| is - |%s|\n", ch, ret);
	return (0);
} */
