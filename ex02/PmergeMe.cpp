/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 13:06:02 by busseven          #+#    #+#             */
/*   Updated: 2026/11/14 15:41:14 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

const std::vector<int> &PmergeMe::get_vec() const
{
	return (_vec);
}

const std::deque<int> &PmergeMe::get_deq() const
{
	return (_deq);
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if(this != &other)
	{
		this->_vec = other.get_vec();
		this->_deq = other.get_deq();	
	}
	return (*this);
}

PmergeMe::~PmergeMe(){}

void PmergeMe::fillVector(int argc, char **argv)
{
	_vec.clear();
	_vec.reserve(argc - 1);
    for (int i = 1; i < argc; ++i)
        _vec.push_back(std::atoi(argv[i]));
}

void PmergeMe::fillDeque(int argc, char **argv)
{
	_deq.clear();
    for (int i = 1; i < argc; ++i)
        _deq.push_back(std::atoi(argv[i]));
}

void PmergeMe::sortDeque()
{
	;
}

void PmergeMe::sortVector()
{
	std::size_t i = 0;
	std::vector<std::pair<int, int> > pairs;
	bool hasStraggler = (_vec.size() % 2 != 0);
	int straggler = 0;
	if(hasStraggler)
		straggler = _vec[_vec.size() - 1];
	
	while(i + 1 < _vec.size())
	{
		int temp;
		std::pair<int, int> p;
		p.first = _vec[i];
		p.second = _vec[i + 1];
		if(p.second > p.first)
		{
			temp = p.first;
			p.first = p.second;
			p.second = temp;
		}
		pairs.push_back(p);
		i+=2;
	}
	std::sort(pairs.begin(), pairs.end());

	for (std::size_t k = 0; k < pairs.size(); ++k)
   		std::cout << "(" << pairs[k].first << "," << pairs[k].second << ") ";
	std::cout << std::endl;
	if (hasStraggler)
    	std::cout << "straggler: " << straggler << std::endl;
}