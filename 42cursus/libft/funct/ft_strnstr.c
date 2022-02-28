/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:30:07 by ysantos-          #+#    #+#             */
/*   Updated: 2022/02/27 18:30:07 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char	*cmp, const char *src, size_t len)
{
	int	a;
	int	b;

	a = 0;
	if (src[0] == '\0')
		return ((char *)cmp);
	while (cmp[a])
	{
		b = 0;
		while (src[b] == cmp[a] && src[b])
		{
			if (src[b + 1] == '\0')
				return (&((char *)cmp)[a]);
			++b;
		}
		++a;
	}
	return (0);
}
