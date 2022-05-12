/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:58:18 by gfaviere          #+#    #+#             */
/*   Updated: 2021/10/29 19:22:51 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	free_line(char *line_read)
{
	if (line_read)
	{
		free(line_read);
		line_read = (char *) NULL;
	}
}

void	ft_exit(t_struct *xpt)
{
	free_char_array2(xpt->commands);
	if (xpt->path)
		free_char_array(xpt->path);
	free (xpt->home);
	printf("exit\n");
	exit(0);
}

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

void	free_char_array2(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
}
