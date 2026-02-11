/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:48:21 by caide-so          #+#    #+#             */
/*   Updated: 2026/02/09 23:12:43 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE
#define BITCOIN_EXCHANGE

#include <map>
#include <string>

class	BitcoinExchange
{
	private:
		std::map<std::string, double>	_data;

		static std::string	trim(const std::string &str);
		static bool		isValidDate(const std::string &date);
		static bool		isValidNumber(const std::string &str, double &value);

	public:
		BitcoinExchange();
                BitcoinExchange(const BitcoinExchange &other);
                BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	loadDatabase(const std::string &filename);
		double	getRate(const std::string &date) const;
		void	processInputFile(const std::string &filename) const;
};

#endif
