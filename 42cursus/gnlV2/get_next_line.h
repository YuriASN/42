/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:00:27 by ysantos-          #+#    #+#             */
/*   Updated: 2022/05/30 19:43:17 by ysantos-         ###   ########.fr       */
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
size_t	part_size(const char *str);
int		buf_to_arr(char **arr, char *buffer);
int		check_binary(const char *str);
int		read_n_check(int fd, char *str);
size_t	get_lines(const char *buffer);
//size_t	ft_strlen(const char *str);

#endif