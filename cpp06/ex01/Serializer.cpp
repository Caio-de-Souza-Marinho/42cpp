/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 22:21:36 by caide-so          #+#    #+#             */
/*   Updated: 2026/01/25 22:51:49 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	return ;
}

Serializer::~Serializer()
{
	return ;
}

Serializer::Serializer(const Serializer &other)
{
	(void)other;
	return ;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
