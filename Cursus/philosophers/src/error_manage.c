/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 06:49:26 by marvin            #+#    #+#             */
/*   Updated: 2021/07/21 12:46:50 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	write_error(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(2, "Error: ", 7);
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

int	error_manage(int error)
{
	if (error == 1)
		return (write_error("Some argument is incorrect"));
	if (error == 2)
		return (write_error("Error when initializing mutex"));
	return (1);
}
