/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:09:25 by estina            #+#    #+#             */
/*   Updated: 2019/09/25 19:39:16 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_reading(char *string, char ptr, int size)
{
	char	*clone;
	char	aux[2];

	clone = malloc(size + 8);
	ft_strcpy(clone, string);
	aux[0] = ptr;
	aux[1] = '\0';
	ft_strcat(clone, aux);
	free(string);
	return (clone);
}

char	*ft_read_extern(void)
{
	char	*string;
	char	ptr;
	int		i;

	i = 0;
	string = malloc(2);
	while (read(STDIN_FILENO, &ptr, 1))
		string = ft_reading(string, ptr, i++);
	string[i] = '\0';
	return (string);
}
