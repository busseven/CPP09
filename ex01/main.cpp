/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:03:15 by busseven          #+#    #+#             */
/*   Updated: 2026/11/05 16:05:54 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include "RPN.hpp"

int main(int argc, char **argv)
{
    long result;

    if (argc != 2 || !compute(argv[1], result))
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    std::cout << result << std::endl;
    return (0);
}