/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:58:29 by caide-so          #+#    #+#             */
/*   Updated: 2026/02/04 11:36:23 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND
#define EASYFIND

#include <algorithm>

template <typename T>
void	easyfind(const T &container, int value)
{
	if (std::find(container.begin(), container.end(), value) == container.end())
		throw std::exception();
}

#endif
