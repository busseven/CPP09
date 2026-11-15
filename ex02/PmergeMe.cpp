/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 13:06:02 by busseven          #+#    #+#             */
/*   Updated: 2026/11/15 14:33:41 by busseven         ###   ########.fr       */
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
	fordJohnson(_deq);;
}

void PmergeMe::sortVector()
{
	fordJohnson(_vec);
}

static std::vector<std::size_t> insertionOrder(std::size_t m)
{
    std::vector<std::size_t> order;
    std::size_t done = 1;
    std::size_t prev = 1;
    std::size_t cur = 3;
    while (done < m)
    {
        std::size_t top = (cur < m) ? cur : m;
        for (std::size_t i = top; i > done; --i)
            order.push_back(i);
        done = top;

        std::size_t next = cur + 2 * prev;
        prev = cur;
        cur = next;
    }
    return (order);
}

static std::deque<std::size_t> insertionOrder_deq(std::size_t m)
{
    std::deque<std::size_t> order;
    std::size_t done = 1;
    std::size_t prev = 1;
    std::size_t cur = 3;
    while (done < m)
    {
        std::size_t top = (cur < m) ? cur : m;
        for (std::size_t i = top; i > done; --i)
            order.push_back(i);
        done = top;

        std::size_t next = cur + 2 * prev;
        prev = cur;
        cur = next;
    }
    return (order);
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

static void binaryInsert(std::deque<int> &chain, std::size_t end, int value)
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
	std::vector<std::pair<int, int> > sorted;
	std::vector<bool> used(pairs.size(), false);
	for (std::size_t a = 0; a < winners.size(); ++a)
	{
		for(std::size_t j = 0; j < pairs.size(); ++j)
		{
			if(!used[j] && pairs[j].first == winners[a])
			{
				used[j] = true;
				sorted.push_back(pairs[j]);
				break ;
			}
		}	
	}
	pairs = sorted;
	if (!pairs.empty())
	{
    	chain.push_back(pairs[0].second);
    	for (std::size_t k = 0; k < pairs.size(); ++k)
        	chain.push_back(pairs[k].first);
	}
	std::size_t m = pairs.size() + (hasStraggler ? 1 : 0);
	std::vector<std::size_t> order = insertionOrder(m);
	for (std::size_t o = 0; o < order.size(); ++o)
	{
		std::size_t k = order[o];
		if (k <= pairs.size())
		{
   			std::size_t end = std::find(chain.begin(), chain.end(), pairs[k - 1].first) - chain.begin();
    		binaryInsert(chain, end, pairs[k - 1].second);	
		}
		else
		{
    		binaryInsert(chain, chain.size(), straggler);	
		}
	}
	v = chain;
}

void PmergeMe::fordJohnson(std::deque<int> &v)
{
	if (v.size() < 2)
    	return ;
	std::size_t i = 0;
	std::deque<std::pair<int, int> > pairs;
	std::deque<int> chain;

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
	std::deque<int> winners;
	for (std::size_t k = 0; k < pairs.size(); ++k)
    	winners.push_back(pairs[k].first);
	fordJohnson(winners);
	std::deque<std::pair<int, int> > sorted;
	std::deque<bool> used(pairs.size(), false);
	for (std::size_t a = 0; a < winners.size(); ++a)
	{
		for(std::size_t j = 0; j < pairs.size(); ++j)
		{
			if(!used[j] && pairs[j].first == winners[a])
			{
				used[j] = true;
				sorted.push_back(pairs[j]);
				break ;
			}
		}	
	}
	pairs = sorted;
	if (!pairs.empty())
	{
    	chain.push_back(pairs[0].second);
    	for (std::size_t k = 0; k < pairs.size(); ++k)
        	chain.push_back(pairs[k].first);
	}
	std::size_t m = pairs.size() + (hasStraggler ? 1 : 0);
	std::deque<std::size_t> order = insertionOrder_deq(m);
	for (std::size_t o = 0; o < order.size(); ++o)
	{
		std::size_t k = order[o];
		if (k <= pairs.size())
		{
   			std::size_t end = std::find(chain.begin(), chain.end(), pairs[k - 1].first) - chain.begin();
    		binaryInsert(chain, end, pairs[k - 1].second);	
		}
		else
		{
    		binaryInsert(chain, chain.size(), straggler);	
		}
	}
	v = chain;
}
