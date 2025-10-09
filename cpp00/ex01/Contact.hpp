/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:53:10 by caide-so          #+#    #+#             */
/*   Updated: 2025/10/08 12:11:00 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef CONTACT_HPP
# define CONTACT_HPP

class	Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		void	setFirstName(void);
		void	setLastName(void);
		void	setNickname(void);
		void	setPhoneNumber(void);
		void	setDarkestSecret(void);
		void	setContact(void);
		
		const std::string&	getFirstName(void) const;
		const std::string&	getLastName(void) const;
		const std::string&	getNickname(void) const;
		const std::string&	getPhoneNumber(void) const;
		const std::string&	getDarkestSecret(void) const;
		void			displayFullContact(void);
};

#endif
