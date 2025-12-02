/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:45:45 by eieong            #+#    #+#             */
/*   Updated: 2025/12/02 12:08:22 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("NoName", 145, 137)
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name) : AForm(name, 145, 137)
{
	std::cout << "ShrubberyCreationForm Parametric constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	(void) rhs;
	return (*this);
}
