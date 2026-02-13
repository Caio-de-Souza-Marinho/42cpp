/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 07:44:45 by caide-so          #+#    #+#             */
/*   Updated: 2026/02/13 07:45:26 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class	RPN
{
	private:
		std::stack<int>	_stack;

		void	processToken(const std::string &token);
		bool	isOperator(char c) const;
		void	applyOperator(char op);

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		void	evaluate(const std::string &expr);
};

#endif
