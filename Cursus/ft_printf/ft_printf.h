/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 22:17:01 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/21 22:44:04 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_struct
{
	char			*str;
	va_list			ap;
	char			tipoimpr;
	char			flag;
	int				max;
	int				min;
	int				total;
	int				neg;
	int				aux;
}					t_struct;

int					ft_printf(const char *str, ...);
char				ft_flag(t_struct *general, char y);
char				ft_searchimpr(t_struct *general);

void				ft_imprimirtodo(t_struct *general);
void				ft_printchar(t_struct *general, int x);
void				ft_printstr(t_struct *general, char *x);
void				ft_printint(t_struct *general, char *x);
void				ft_printint0(t_struct *general);
void				ft_printintneg(t_struct *general, char *x);
void				ft_printpointer(t_struct *general, char *x);
void				ft_printporcentaje(t_struct *general);
void				ft_printhex(t_struct *general, char *x);
void				ft_printhex0(t_struct *general);

int					ft_atoispecial(t_struct *general);

void				ft_putstr(t_struct *general, char *str);
void				ft_putnstr(t_struct *general, char *str, size_t x);
void				ft_putnegativo(t_struct *general);
void				ft_putspacemin(t_struct *general);
void				ft_putzeromin(t_struct *general);
void				ft_putzeromax(t_struct *general);

char				*ft_calchex(unsigned int n);
char				*ft_calchexlong(unsigned long n);

#endif
