/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 13:03:12 by busseven          #+#    #+#             */
/*   Updated: 2026/11/14 17:42:23 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>

class PmergeMe
{
	public:
    	PmergeMe();
    	PmergeMe(const PmergeMe &other);
   		PmergeMe &operator=(const PmergeMe &other);
   		~PmergeMe();

		void fordJohnson(std::vector<int> &v);
    	void sortVector();
    	void sortDeque();
		void fillVector(int argc, char **argv);
		void fillDeque(int argc, char **argv);
		const std::vector<int> &get_vec() const;
		const std::deque<int>	&get_deq() const;

	private:
    	std::vector<int> _vec;
    	std::deque<int>  _deq;
};