/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calchex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 04:20:07 by gfaviere          #+#    #+#             */
/*   Updated: 2019/12/13 16:48:48 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_dectohex2(unsigned int n)
{
	char				*hexnum;
	unsigned int		i;
	unsigned int		temp;

	i = 0;
	if (!(hexnum = (char*)malloc(sizeof(char*) * (ft_strlen(ft_itoa(n))) + 1)))
		return (0);
	while (n != 0)
	{
		temp = 0;
		temp = n % 16;
		if (temp < 10)
			hexnum[i] = (char)(temp + 48);
		else
			hexnum[i] = (char)(temp + 55);
		n = n / 16;
		i++;
	}
	hexnum[i] = '\0';
	return (hexnum);
}

char			*ft_calchex(unsigned int n)
{
	char				*hexnum;
	char				*hexnumrev;
	unsigned int		x;
	unsigned int		i;

	if (n == 0)
	{
		if (!(hexnum = (char*)malloc(sizeof(char*) + 2)))
			return (0);
		hexnum[0] = '0';
		hexnum[1] = '\0';
		return (hexnum);
	}
	hexnum = ft_dectohex2(n);
	x = 0;
	i = ft_strlen(hexnum);
	if (!(hexnumrev = (char*)malloc(sizeof(char*) * (i + 1))))
		return (0);
	while (x < i)
	{
		hexnumrev[x] = hexnum[i - x - 1];
		x++;
	}
	hexnumrev[x] = '\0';
	return (hexnumrev);
}

static char		*ft_dectohexlong(unsigned long n)
{
	char	*hexnum;
	int		i;
	int		temp;

	i = 0;
	if (!(hexnum = (char*)malloc(sizeof(char*) * (ft_strlen(ft_itoa(n))) + 1)))
		return (0);
	while (n != 0)
	{
		temp = 0;
		temp = n % 16;
		if (temp < 10)
			hexnum[i] = (char)(temp + 48);
		else
			hexnum[i] = (char)(temp + 55);
		n = n / 16;
		i++;
	}
	hexnum[i] = '\0';
	return (hexnum);
}

char			*ft_calchexlong(unsigned long n)
{
	char	*hexnum;
	char	*hexnumrev;
	int		x;
	int		i;

	if (n == 0)
	{
		if (!(hexnum = (char*)malloc(sizeof(char*) + 2)))
			return (0);
		hexnum[0] = '0';
		hexnum[1] = '\0';
		return (hexnum);
	}
	hexnum = ft_dectohexlong(n);
	x = 0;
	i = ft_strlen(hexnum);
	if (!(hexnumrev = (char*)malloc(sizeof(char*) * (i + 1))))
		return (0);
	while (x < i)
	{
		hexnumrev[x] = hexnum[i - x - 1];
		x++;
	}
	hexnumrev[x] = '\0';
	return (hexnumrev);
}
