/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 13:06:02 by busseven          #+#    #+#             */
/*   Updated: 2026/11/14 17:30:33 by busseven         ###   ########.fr       */
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

static void binaryInsert(std::vector<int> &chain, std::size_t end, int value)
{
    std::size_t lo = 0;
    std::size_t hi = end;

    while (lo < hi)
    {
        std::size_t mid = lo + (hi - lo) / 2;
        if (chain[mid] < value)
            lo = mid + 1;
        else
            hi = mid;
    }
    chain.insert(chain.begin() + lo, value);
}

void PmergeMe::fordJohnson(std::vector<int> &v)
{
	if (v.size() < 2)
    	return ;
	std::size_t i = 0;
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> chain;

	bool hasStraggler = (v.size() % 2 != 0);
	int straggler = 0;
	if(hasStraggler)
		straggler = v[v.size() - 1];
	
	while(i + 1 < v.size())
	{
		int temp;
		std::pair<int, int> p;
		p.first = v[i];
		p.second = v[i + 1];
		if(p.second > p.first)
		{
			temp = p.first;
			p.first = p.second;
			p.second = temp;
		}
		pairs.push_back(p);
		i+=2;
	}
	std::vector<int> winners;
	for (std::size_t k = 0; k < pairs.size(); ++k)
    	winners.push_back(pairs[k].first);
	fordJohnson(winners);
	if (!pairs.empty())
	{
    	chain.push_back(pairs[0].second);
    	for (std::size_t k = 0; k < pairs.size(); ++k)
        	chain.push_back(pairs[k].first);
	}
	for (std::size_t k = 1; k < pairs.size(); ++k)
	{
   		std::size_t end = std::find(chain.begin(), chain.end(), pairs[k].first) - chain.begin();
    	binaryInsert(chain, end, pairs[k].second);
	}
	if (hasStraggler)
    	binaryInsert(chain, chain.size(), straggler);
	v = chain;
}