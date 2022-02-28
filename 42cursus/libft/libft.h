/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysantos- <ysantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:46:45 by ysantos-          #+#    #+#             */
/*   Updated: 2022/02/27 21:46:45 by ysantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_strlen(char *str);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char	*cmp, const char *src, size_t len);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

void	*ft_memset(void *str, int c, int bytes);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*memchr(const void *str, int c, size_t bytes);

int		ft_isprint(int x);
int		ft_isdigit(int x);
int		ft_isascii(int x);
int		ft_isalpha(int x);
int		ft_isalnum(int x);
int		ft_tolower(int x);
int		ft_toupper(int x);

void	ft_bzero(void *s, size_t bytes);
int		ft_atoi(const char *str);

#endif
