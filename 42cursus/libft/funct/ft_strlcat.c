/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:56:29 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/13 18:17:09 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
strlcat() take the full size of the buffer (not just the length)
and guarantee to NUL-terminate the result
(as long as size is larger than 0 or, in the case of strlcat(),
as long as there is at least one byte free in dst).
#Note that a byte for the NULL should be included in size.
 */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;

	a = ft_strlen(dst);
	if (dstsize <= a + ft_strlen(src))
		return (a + ft_strlen(src));
	else
		ft_strlcpy(&dst[a], src, ft_strlen(src) + 1);
	dst[ft_strlen(dst)] = '\0';
	return (ft_strlen(dst));
}

/* int	main(void)
{
	int		ret;
	char	from[20] = "termina.";
	char	to[20] = "Comeca e ";

	ret = ft_strlcat(to, from, 18);
	printf("%s\n%d\n", to, ret);
	return (0);
} */
