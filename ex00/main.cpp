/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:30:38 by ioleinik          #+#    #+#             */
/*   Updated: 2021/12/04 13:29:13 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	srand(time(NULL));
	std::vector<int> v;

	for (int i = 0; i < 6; i++)
		v.push_back(rand() % 6);

	std::for_each(v.begin(), v.end(), put<int>);
	std::cout << std::endl;

	for (int i = 0; i < 7; i++)
	{
		try
		{
			std::vector<int>::iterator it = easyfind(v, i);
			std::cout << "found: " << *it << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}