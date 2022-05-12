/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:36:07 by gfaviere          #+#    #+#             */
/*   Updated: 2021/10/29 19:25:08 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*new_command(int i, char **str)
{
	char	*aux;

	aux = ft_strdup("");
	while (str[i] != NULL)
	{
		if (ft_strlen(aux) > 0)
			aux = ft_strjoin(aux, " ");
		aux = ft_strjoin(aux, str[i]);
		i++;
	}
	return (aux);
}

static void	read_until(char *end)
{
	char	*line;
	int		flags;
	int		fd;

	flags = O_WRONLY | O_CREAT | O_TRUNC;
	line = ft_strdup("");
	fd = open(end, flags, 0777);
	while (ft_strncmp(line, end, ft_strlen(end))
		|| ft_strlen(line) != ft_strlen(end))
	{
		free(line);
		line = readline("> ");
		if (ft_strlen(line) != ft_strlen(end))
			ft_putendl_fd(line, fd);
	}
	close(fd);
	free(line);
}

static char	**double_redir(t_struct *xpt, char **file, int j)
{
	file = ft_split(&xpt->commands[j][2], ' ');
	read_until (file[0]);
	xpt->in_fd = open(file[0], O_RDONLY | O_CREAT, 0777);
	xpt->name_file = ft_strdup(file[0]);
	xpt->is_append++;
	return (file);
}

void	redirect_in(t_struct *xpt, int j, char *aux)
{
	char	**file;

	if (xpt->commands[j][0] == '<')
	{
		file = NULL;
		if (xpt->commands[j][1] == '<')
			file = double_redir(xpt, file, j);
		else
		{
			file = ft_split(&xpt->commands[j][1], ' ');
			xpt->in_fd = open(file[0], O_RDONLY, 0777);
			if (xpt->in_fd == -1 && xpt->error_name_file == NULL)
				xpt->error_name_file = ft_strdup(file[0]);
		}
		aux = ft_strtrim(xpt->line, " ");
		if (xpt->split.n_comand == 1 || (aux[0] == '|'
				&& ft_strlen(aux) == 1))
		{
			free(xpt->line);
			xpt->line = new_command(1, file);
		}
		free(aux);
		xpt->last_redir = 0;
		free_char_array(file);
	}
}
