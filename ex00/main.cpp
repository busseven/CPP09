/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 14:56:49 by busseven          #+#    #+#             */
/*   Updated: 2026/11/15 14:24:59 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		if(argc != 2)
		{
			std::cerr << "Invalid argument count. Try ./btc input.txt" << std::endl;
			return (1);
		}
		std::map<std::string, double> cont;
		cont = get_database_container();
		process_input_file(argv[1], cont);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
