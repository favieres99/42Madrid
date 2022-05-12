/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:37:17 by gfaviere          #+#    #+#             */
/*   Updated: 2021/10/29 18:37:36 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	init_path(t_struct *xpt)
{
	char	*path_aux;
	int		i;

	path_aux = ft_strdup(find_env(xpt, "PATH"));
	if (!path_aux)
		return (0);
	xpt->path = ft_split(path_aux, ':');
	i = 0;
	while (xpt->path && xpt->path[i])
	{
		xpt->path[i] = ft_strjoin(xpt->path[i], "/");
		i++;
	}
	free(path_aux);
	return (1);
}
