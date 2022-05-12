/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:00:18 by marvin            #+#    #+#             */
/*   Updated: 2021/12/14 19:00:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_H
# define KAREN_H

#include <string>
#include <iostream>

class Karen{

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		Karen();
		~Karen();
		void complain(std::string i);
};

#endif