/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:49:42 by ysantos-          #+#    #+#             */
/*   Updated: 2022/03/13 21:53:49 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		cpy[i] = str[i];
		++i;
	}
	cpy[i] = '\0';
	return (cpy);
}

/* int	main(void)
{
	char	source[] = "GeeksForGeeks";
	char	*target = ft_strdup(source);

	printf("Source: %s\nTarget: %s\n", source, target);
	return (0);
} */
