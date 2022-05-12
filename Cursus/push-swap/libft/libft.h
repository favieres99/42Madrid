/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:13:59 by gfaviere          #+#    #+#             */
/*   Updated: 2021/06/09 21:15:52 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 1
# include "fcntl.h"
# include "sys/types.h"
# include "sys/uio.h"

int		get_next_line(const int fd, char **line);

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		ft_write(char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
void	ft_strdel(char **as);
char	**ft_strsplit(char const *s, char c);
int		ft_strequ(char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);
void	ft_putstr(char const *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_abs(int nbr);
int		ft_free_array(char **array, int ret_val);
char	*ft_itoa(int n);
size_t	ft_w_count(char const *s, char c);

#endif
