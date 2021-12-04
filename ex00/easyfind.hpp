/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:30:52 by ioleinik          #+#    #+#             */
/*   Updated: 2021/12/04 13:25:58 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>
#include <iostream>

class NotFoundException
	: public std::exception
{
public:
	char const *what() const throw()
	{
		return ("Value not found");
	}
};

template <typename T>
void put(T &a)
{
	std::cout << a << " ";
}

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator i;

	i = std::find(container.begin(), container.end(), value);
	if (i == container.end())
		throw NotFoundException();
	return (i);
}

#endif