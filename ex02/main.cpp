/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 13:05:31 by busseven          #+#    #+#             */
/*   Updated: 2026/11/14 13:26:20 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cerrno>
#include <climits>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include "PmergeMe.hpp"

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
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }

    std::vector<int> vec;
    std::deque<int>  deq;

    for (int i = 1; i < argc; ++i)
    {
        int n;
        if (!parse_arg(argv[i], n))
        {
            std::cerr << "Error" << std::endl;
            return (1);
        }
        vec.push_back(n);
        deq.push_back(n);
    }
	PmergeMe sort(vec, deq);
    print_container("Before:", sort.get_vec());
    return (0);
}