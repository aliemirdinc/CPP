/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:55:55 by aldinc            #+#    #+#             */
/*   Updated: 2026/02/16 18:56:08 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <cstdlib>

class BitcoinExchange {
	private:
		std::map<std::string, float> _database;

		std::string _trim(const std::string& str);
		bool		_isValidDate(const std::string& date);
		bool		_isValidValue(const std::string& valueStr, float &value);
		void		_loadDatabase();

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void run(const std::string& filename);
};

#endif