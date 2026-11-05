/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 14:56:49 by busseven          #+#    #+#             */
/*   Updated: 2026/11/05 15:35:30 by busseven         ###   ########.fr       */
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

bool 	is_valid_value(const std::string &str)
{
	int	dotcount = 0;
	int digits = 0;
	std::string::size_type i = 0;

	if(i < str.length() && str[i] == ' ')
		i++;
	if(i < str.length() && str[i] == '-')
		i++;
	while(i < str.length())
	{
		if(str[i] == '.')
			dotcount++;
		else if(str[i] < '0' || str[i] > '9')
			return (false);
		else
			digits++;
		if(dotcount > 1)
			return (false);
		i++;
	}
	if (digits > 0)
		return (true);
	else
		return (false);
}

bool	is_valid_date(std::string &date)
{
	if(date.length() == 11 && date[10] == ' ')
	{
		date.erase(date.length() - 1);	
	}
	if(date.length() != 10)
		return (false);
	if(date[4] != '-' || date[7] != '-')
		return (false);
    for (std::string::size_type i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue ;
        if (date[i] < '0' || date[i] > '9')
            return (false);
    }

    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1)
        return (false);

    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        days_in_month[1] = 29;
    return (day <= days_in_month[month - 1]);
}

void    print_result(const std::map<std::string, double> &cont,
                     const std::string &date, double value)
{
    std::map<std::string, double>::const_iterator it = cont.upper_bound(date);

    if (it == cont.begin())
    {
        std::cerr << "Error: date too early => " << date << std::endl;
        return ;
    }
    --it;
    std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}

void	process_input_file(const std::string &filename, const std::map<std::string, double> &cont)
{
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
			continue ;		
		}
		value_str = line.substr(pipe + 1);
		if(!is_valid_value(value_str))
		{
			std::cerr << "Error: invalid value => " << line << std::endl;
			continue ;
		}
		value = std::strtod(value_str.c_str(), NULL);
		if (value < 0)
		{
			std::cerr << "Error: not a positive number" << std::endl;
			continue ;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number" << std::endl;
			continue ;	
		}
		print_result(cont, date, value);
	}
}

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