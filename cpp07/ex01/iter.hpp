/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:48:36 by caide-so          #+#    #+#             */
/*   Updated: 2026/01/28 15:42:49 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void	iter(T* arr, const int size, void (*f)(const T&))
{
	for (int i = 0; i < size; i++)
      		f(arr[i]);
}

#endif
