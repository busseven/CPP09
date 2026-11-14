/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 13:06:02 by busseven          #+#    #+#             */
/*   Updated: 2026/11/14 14:01:48 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
	;
}