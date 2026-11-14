/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 13:06:02 by busseven          #+#    #+#             */
/*   Updated: 2026/11/14 13:24:55 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(std::vector<int> vec, std::deque<int> deq): _vec(vec), _deq(deq){}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

std::vector<int> PmergeMe::get_vec() const
{
	return (_vec);
}

std::deque<int> PmergeMe::get_deq() const
{
	return (_deq);
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	this->_vec = other.get_vec();
	this->_deq = other.get_deq();
	return (*this);
}

PmergeMe::~PmergeMe(){};