/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 09:53:10 by caide-so          #+#    #+#             */
/*   Updated: 2026/01/28 10:37:06 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

template <typename T>
void	swap(T& a, T& b)
{
	T aux = a;
	a = b;
	b = aux;
}

template <typename T>
const T&	min(const T&a, const T&b)
{
	if (a == b)
		return (b);
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
const T&	max(const T&a, const T&b)
{
	if (a == b)
		return (b);
	if (a > b)
		return (a);
	return (b);
}

#endif
