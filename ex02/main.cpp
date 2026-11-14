/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 13:05:31 by busseven          #+#    #+#             */
/*   Updated: 2026/11/14 14:20:05 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cerrno>
#include <climits>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sys/time.h>
#include "PmergeMe.hpp"

static double now_us()
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (static_cast<double>(tv.tv_sec) * 1000000.0
            + static_cast<double>(tv.tv_usec));
}

static bool parse_arg(const char *s, int &out)
{
    if (*s == '\0')
        return (false);
    for (const char *p = s; *p; ++p)
    {
        if (*p < '0' || *p > '9')
    	    return (false);
    }
    errno = 0;
    long n = std::strtol(s, NULL, 10);
    if (errno == ERANGE || n > INT_MAX)
        return (false);
    if (n == 0)
        return (false);
    out = static_cast<int>(n);
    return (true);
}

template <typename Container>
static void print_container(const std::string &label, const Container &c)
{
    std::cout << label;
    for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
	PmergeMe sort;

    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    for (int i = 1; i < argc; ++i)
    {
        int n;
        if (!parse_arg(argv[i], n))
        {
            std::cerr << "Error" << std::endl;
            return (1);
        }
    }
    std::cout << "Before:";
    for (int i = 1; i < argc; ++i)
        std::cout << " " << argv[i];
    std::cout << std::endl;

	double vStart = now_us();
	sort.fillVector(argc, argv);
	sort.sortVector();
	double vEnd = now_us();

	double dStart = now_us();
	sort.fillDeque(argc, argv);
	sort.sortDeque();
	double dEnd = now_us();

	print_container("After:", sort.get_vec());

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << sort.get_vec().size()
          	<< " elements with std::vector : "
          	<< (vEnd - vStart) << " us" << std::endl;
	std::cout << "Time to process a range of " << sort.get_deq().size()
        	<< " elements with std::deque  : "
        	<< (dEnd - dStart) << " us" << std::endl;
	return (0);
}