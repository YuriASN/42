/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:28:56 by ysantos-          #+#    #+#             */
/*   Updated: 2022/02/27 22:28:56 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The calloc() function allocates space for number	objects, each size
bytes in	length.	The result is identical	to calling malloc() with an
argument	of number * size, with the exception that the allocated	memory
is explicitly initialized to zero bytes.
*/
#include <stdlib.h>

void	*ft_calloc(size_t number, size_t size)
{
	if (number < 1 || size < 1)
		return (0);
	else
		return (malloc(number * size));
}
