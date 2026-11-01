/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 14:56:49 by busseven          #+#    #+#             */
/*   Updated: 2026/11/01 15:57:12 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <map>
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>

int main()
{
	std::ifstream csvfile("data.csv");
	std::map<std::string, double> date_exchange;
	std::string line;

	std::getline(csvfile, line);
	while(std::getline(csvfile, line))
	{
		std::string	date;
		double		exchange_rate;
		std::string	exchange_rate_str;
		int			comma;

		comma = line.find(",");
		date = line.substr(0, comma);
		exchange_rate_str = line.substr(comma + 1);
		exchange_rate = std::strtod(exchange_rate_str.c_str(), NULL);
		date_exchange[date] = exchange_rate;
	}
}