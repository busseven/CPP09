/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 13:03:12 by busseven          #+#    #+#             */
/*   Updated: 2026/11/14 13:15:22 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>

class PmergeMe
{
	public:
    	PmergeMe();
    	PmergeMe(const PmergeMe &other);
		PmergeMe(std::vector<int> vec, std::deque<int> deq);
   		PmergeMe &operator=(const PmergeMe &other);
   		~PmergeMe();

    	void sortVector();
    	void sortDeque();
		std::vector<int> get_vec() const;
		std::deque<int>	get_deq() const;

	private:
    	std::vector<int> _vec;
    	std::deque<int>  _deq;
};