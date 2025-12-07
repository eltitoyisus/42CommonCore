/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:01:57 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/17 13:01:57 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::createFile() const {
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file) {
		std::cerr << "Error creating file: " << _target << "_shrubbery" << std::endl;
		return;
	}
	file << makeTree();
	file.close();
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!getSigned())
		throw std::runtime_error("Form not signed");
	if (executor.getGrade() > getExec())
		throw GradeTooLowException();
	createFile();
}

std::string ShrubberyCreationForm::makeTree() const {
	return

	"       _-_\n"
	"    /~~   ~~\\\n"
	"  /~~         ~~\\\n"
	" /~~           ~~\\\n"
	" |               |\n"
	" |               |\n"
	" \\~~           ~~/\n"
	"  \\~~         ~~/\n"
	"    \\__-__-__/\n"
	"       |||\n"
	"       |||\n"
	"\n"

	"        v\n"
	"       >X<\n"
	"        A\n"
	"       d$b\n"
	"     .d\\$$b.\n"
	"   .d$i$$\\$$b.\n"
	"     d$$@b\n"
	"    d\\$$$ib\n"
	"  .d$$$\\$$$b\n"
	" .d$$@$$$$\\$$ib.\n"
	"     d$$i$$b\n"
	"    d\\$$$$@$b\n"
	" .d$@$$\\$$$$$@b.\n"
	".d$$$$i$$$\\$$$$$$b.\n"
	"      ###\n"
	"      ###\n"
	"      ###\n"
	"\n"

	"    ^\n"
	"   /|\\\n"
	"  //|\\\\\n"
	" ///|\\\\\\\n"
	"   |||\n"
	"   |||\n"
	"\n"

	"      ccee88oo\n"
	"   C8O8O8Q8PoOb o8oo\n"
	" dOB69QO8PdUOpugoO9bD\n"
	"CgggbU8OU qOp qOdoUOdcb\n"
	"    6OuU  /p u gcoUodpP\n"
	"      \\\\\\//  /douUP\n"
	"        \\\\////\n"
	"         |||/\\\n"
	"         |||\\/\n"
	"         |||||\n"
	"   .....//||||\\....\n"
	"\n"

	"     .     .  .      +     .      .          .\n"
	" .       .      .     #       .           .\n"
	"     .      .         ###            .      .      .\n"
	"   .      .   '#:. .:##'##:. .:#'  .      .\n"
	"       .      . '####'###'####'  .\n"
	"    .     '#:.    .:#'###'#:.    .:#'  .        .       .\n"
	" .             '#########'#########'        .        .\n"
	"       .    '#:.  '####'###'####'  .:#'   .       .\n"
	"    .     .  '#######''##'##''#######'                  .\n"
	"               .'##'#####'#####'##'           .      .\n"
	"   .   '#:. ...  .:##'###'###'##:.  ... .:#'     .\n"
	"     .     '#######'##'#####'##'#######'      .     .\n"
	"   .    .     '#####''#######''#####'    .      .\n"
	"           .     '      000      '    .     .\n"
	"      .         .   .   000     .        .       .\n"
	".. .. ..................O000O........................ ...... ...\n";
}
