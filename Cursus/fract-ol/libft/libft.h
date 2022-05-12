/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:13:59 by gfaviere          #+#    #+#             */
/*   Updated: 2021/06/15 13:53:10 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char const *s);
void	ft_error(char *str);
void	ft_putstr_fd(char const *s, int fd);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);

#endif
