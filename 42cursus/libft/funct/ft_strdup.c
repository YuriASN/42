/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:49:42 by ysantos-          #+#    #+#             */
/*   Updated: 2022/02/27 22:49:42 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*cpy;

	cpy = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (*str)
	{
		*cpy = *str;
		++str;
		++cpy;
	}
	return (cpy);
	free(cpy);
}
