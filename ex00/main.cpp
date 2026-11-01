/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 14:56:49 by busseven          #+#    #+#             */
/*   Updated: 2026/11/01 17:59:42 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <map>
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stdexcept>

std::map<std::string, double>	get_container()
{
	std::ifstream csvfile("data.csv");
    if (!csvfile.is_open())
	{
    	throw std::runtime_error("Error: could not open data.csv");	
	}

	std::map<std::string, double> cont;
	std::string line;
	std::getline(csvfile, line);
	while (std::getline(csvfile, line))
	{
		std::string				date;
		double					exchange_rate;
		std::string				exchange_rate_str;
		std::string::size_type	comma;

		comma = line.find(",");
		if (comma == std::string::npos)
			continue;
		date = line.substr(0, comma);
		exchange_rate_str = line.substr(comma + 1);
		exchange_rate = std::strtod(exchange_rate_str.c_str(), NULL);
		cont[date] = exchange_rate;
	}
	return (cont);
}

int main(int argc, char **argv)
{
	try
	{
		(void)argv;
		if(argc != 2)
		{
			std::cout << "Invalid argument count. Try ./btc input.txt" << std::endl;
			return (1);
		}
		std::map<std::string, double> cont;
		cont = get_container();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}