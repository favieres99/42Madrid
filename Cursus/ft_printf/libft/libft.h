/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:13:59 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/19 02:13:12 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(char *str);
char	ft_isdigit(int n);
size_t	ft_strlen(const char *str);
char	*ft_itoa(unsigned int n);
void	ft_putchar(char c);

#endif
