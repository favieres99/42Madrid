/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:18:45 by gfaviere          #+#    #+#             */
/*   Updated: 2019/09/25 19:39:22 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_map_layout
{
	char			obstacle;
	char			empty;
	char			full;
}				t_map_layout;

typedef struct	s_max
{
	int				value;
	int				row;
	int				col;
}				t_max;

typedef struct	s_map
{
	char			**table;
	int				num_rows;
	int				num_cols;
	t_map_layout	layout;
	t_max			max;
}				t_map;

int				check_obstacles(int x, int y, char **str);
t_map			ft_read_file(char *str);
char			ft_error_check(t_map map);
void			ft_search_solution(t_map *map);
void			ft_draw_sqr(t_map *map);
void			ft_structure_maker(t_map *map, char *aux, int size);
int				ft_ptr_nl(int *row, int *col, t_map *map);
void			ft_ptr_nl_zero(int *row, int *col, char *aux, t_map *map);
void			ft_malloc_table(int row, int col, t_map *map, char *aux);
char			*ft_read_extern(void);
void			ft_read_input(char *input, t_map *map);
#endif
