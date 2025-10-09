/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:55:34 by caide-so          #+#    #+#             */
/*   Updated: 2025/10/09 01:09:11 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
	private:
		Contact	_contactList[8];
		int	_index;

		void	printContactSummary(const Contact& contact, int i);

	public:
		PhoneBook();
		void		addContact(void); 
		void		searchContact(void);
};

#endif
