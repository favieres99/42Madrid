/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfaviere <gfaviere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:00:26 by gfaviere          #+#    #+#             */
/*   Updated: 2021/05/26 16:20:00 by gfaviere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	ft_strlen(char *s)
{
	int i;

	for (i = 0; s && s[i]; i++);
	return (i);
}

char	ft_toupper(char c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
			for (int j = 0; j < ft_strlen(argv[i]); j++)
				std::cout << ft_toupper(argv[i][j]);
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}