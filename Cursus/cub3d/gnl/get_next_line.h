/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:04:51 by gfaviere          #+#    #+#             */
/*   Updated: 2021/03/01 16:11:34 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "utils/utils.h"

# define BUFFER_SIZE 128

typedef struct	s_fd
{
	int			fd;
	t_str		*str;
	struct s_fd	*next;
}				t_fd;

int				get_next_line(int fd, char **line);
t_fd			*find_fd(t_fd **list, int fd, int *new);
int				find_nl(t_str *str, char *sim_str);
int				read_file(t_str **str, char *buffer, int fd);

#endif
