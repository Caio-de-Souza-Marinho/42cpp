/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:40:18 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/27 20:57:40 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	checkExecutionRequirements(executor);

	std::string	filename = _target + "_shrubbery";
	std::ofstream	outfile(filename.c_str());
	if (!outfile.is_open())
	{
		std::cout << "Failed to create output file." << std::endl;
		outfile.close();
		return ;
	}
	outfile << "              _{\\ _{\\{\\/}/}/}__\n";
	outfile << "             {/{/\\}{/{/\\}(\\}{/\\} _\n";
	outfile << "            {/{/\\}{/{/\\}(_)}{/{/\\}  _\n";
	outfile << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n";
	outfile << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n";
	outfile << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n";
	outfile << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}}}\n";
	outfile << "      _{\\{/{\\{/(_)/}{/{/{/\\}\\})}{/\\}}\n";
	outfile << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}}}\n";
	outfile << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n";
	outfile << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}}(_)\n";
	outfile << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}/}/}\n";
	outfile << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}}}\n";
	outfile << "         {/({/{\\{/{\\{\\/}(_){\\/}/}/}(\\}}\n";
	outfile << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n";
	outfile << "            {/{/{\\{\\/}{/{\\{\\{(_)/}}\n";
	outfile << "             {/{\\{\\{\\/}/}{\\{\\\\}/}}\n";
	outfile << "              {){/ {\\/}{\\/} \\}}}\n";
	outfile << "              (_)  \\.-'.-/\n";
	outfile << "          __...---  |'-.-'| --...__\n";
	outfile << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n";
	outfile << " -\"    ' .  . '    |.'-._| '  . .  '   \n";
	outfile << " .  '-  '    .--'   | '-.'|    .  '  . '\n";
	outfile << "          ' ..      |'-_.-|\n";
	outfile << "  .  '  .       _.- |-._ -|-._  .  '  .\n";
	outfile << "              .'    |'- .-|   '.\n";
	outfile << "  ..-'   ' .  '.    `-._.-    .'  '  - .\n";
	outfile << "   .-' '        '-._______.-'     '  .\n";
	outfile << "        .      ~,\n";
}
