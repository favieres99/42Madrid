/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:54:45 by gfaviere          #+#    #+#             */
/*   Updated: 2021/03/16 19:53:25 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM
# define LIBASM

# include <stdlib.h>

size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *dst, const char *str);
int			ft_strcmp(char const *s1, char const *s2);
size_t		ft_read(int fildes, void *buf, size_t nbyte);
size_t		ft_write(int fildes, void const *buf, size_t nbyte);
char		*ft_strdup(char const *s1);

#endif