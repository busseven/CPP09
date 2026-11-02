/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 14:56:49 by busseven          #+#    #+#             */
/*   Updated: 2026/11/02 18:32:32 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <map>
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stdexcept>

std::map<std::string, double>	get_database_container()
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

bool 	is_valid_value(std::string str)
{
	int	dotcount = 0;
	std::string::size_type i = 0;

	if(str[i] == ' ')
		i++;
	if(str[i] == '-')
		i++;
	while(i < str.length())
	{
		if(str[i] == '.')
			dotcount++;
		else if(str[i] < '0' || str[i] > '9')
			return (false);
		if(dotcount > 1)
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid_date(std::string date)
{
	(void)date;
	return (true);
}

void	process_input_file(std::string filename, std::map<std::string, double> &cont)
{
	(void)cont;
	std::ifstream inputfile(filename);
    if (!inputfile.is_open())
	{
    	throw std::runtime_error("Error: could not open input file");	
	}
	std::string line;
	std::getline(inputfile, line);
	while (std::getline(inputfile, line))
	{
		std::string				date;
		double					value;
		std::string				value_str;
		std::string::size_type	pipe;

		pipe = line.find("|");
		if (pipe == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;	
		}
		date = line.substr(0, pipe);
		if(!is_valid_date(date))
		{
			std::cerr << "Error: invalid date => " << line << std::endl;			
		}
		value_str = line.substr(pipe + 1);
		if(!is_valid_value(value_str))
		{
			std::cerr << "Error: invalid value => " << line << std::endl;
			continue ;
		}
		value = std::strtod(value_str.c_str(), NULL);
		std::cout << value << std::endl;
		if(value < 0)
			std::cerr << "Error: not a positive number" << std::endl;
		if(value > 1000)
			std::cerr << "Error: too large a number" << std::endl;
	}
}

int main(int argc, char **argv)
{
	try
	{
		(void)argv;
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