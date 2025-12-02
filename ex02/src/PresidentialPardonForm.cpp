/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:47:01 by eieong            #+#    #+#             */
/*   Updated: 2025/12/02 12:09:43 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("NoName", 25, 5)
{
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
{
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name) : AForm(name, 25, 5)
{
	std::cout << "PresidentialPardonForm Parametric constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
	(void) rhs;
	return (*this);
}
