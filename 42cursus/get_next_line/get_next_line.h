/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:19:04 by ysantos-          #+#    #+#             */
/*   Updated: 2022/05/23 00:33:31 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
size_t	buf_to_str(char *dst, char *src, size_t i);
size_t	part_size(const char *str);
size_t	str_swap(char *dst, char *src, size_t src_start);
void	*free_end(char *str, char *str2);

#endif