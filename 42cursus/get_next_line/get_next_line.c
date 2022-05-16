/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:59:28 by ysantos-          #+#    #+#             */
/*   Updated: 2022/05/16 02:44:46 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char		*buffer;
	static char		*str;
	char			*str2;
	static size_t	i = 0;
	ssize_t			o;

	if (!fd)
		return (0);
	//printf("\t\t\t\tfd = %d\n\n", fd);
	if (i == 0)
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char *));
		if (!buffer)
			return (0);
		o = read(fd, buffer, BUFFER_SIZE);
		buffer[o] = '\0';
		//printf("\e[0;34m1read = |%s|\tread size = %ld\n\e[0;37m", buffer, strlen(buffer));
		if (o < 1)
		{
			//printf("\e[1;92mread failed in first read\n");
			free (buffer);
			return (0);
		}
	}
	o = part_size(buffer);
	if (str)
		free (str);
	str = (char *)malloc((o + 1) * sizeof(char *));
	if (!str)
		return (0);
	i = buf_to_str(str, buffer, i);
	//printf("\nbuffer = |%s|\tstr = |%s|\n", buffer, str);
	//printf("i = %ld\t o = %ld\n", i, o);
	o = ft_strlen(str) - 1;
	while (i == 0 && str[o] != '\n')
	{
		o = read(fd, buffer, BUFFER_SIZE);
		buffer[o] = '\0';
		//printf("\e[0;34m2read = |%s|\tread size = %ld\n\e[0;37m", buffer, strlen(buffer));
		//printf("2buffer = |%s|\tstr = |%s|\n", buffer, str);
		if (o < 1)
		{
			//printf("\e[1;92mread failed in while \n\e[0m");
			free (buffer);
			if (!check_binary(str))
				return (0);
			return (str);
		}
		str2 = (char *)malloc((ft_strlen(str)) * sizeof(char *));
		if (!str2)
		{
			free (buffer);
			if (!check_binary(str))
				return (0);
			return (str);
		}
		ft_strlcpy(str2, str, 0);
		//printf("str2 = |%s|\n", str2);
		free (str);
		str = (char *)malloc(sizeof(char *) * (o + ft_strlen(str2) + 1));
		o = ft_strlcpy(str, str2, 0);
		//printf("str2 = |%s| str = |%s|\n", str2, str);
		i = buf_to_str(&str[o], buffer, 0);
		//printf("BUffer = |%s|\n", buffer);
		//printf("3buffer = |%s|\tstr = |%s|\n", buffer, str);
		o = part_size(str);
		free (str2);
	}
	//printf("\e[0;93mi = %ld\t", i);
	//printf("END Buffer = |%s|\tStr = |%s|\n\e[0m", buffer, str);
	if (!check_binary(str))
		return (0);
	return (str);
}
