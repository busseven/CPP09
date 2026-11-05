/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:45:03 by busseven          #+#    #+#             */
/*   Updated: 2026/11/05 15:46:25 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void							process_input_file(const std::string &filename, const std::map<std::string, double> &cont);
std::map<std::string, double>	get_database_container(void);