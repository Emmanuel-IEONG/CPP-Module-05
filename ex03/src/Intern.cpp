/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:38:50 by eieong            #+#    #+#             */
/*   Updated: 2025/12/05 11:56:03 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(Intern const & src)
{
	std::cout << "Intern Copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern &	Intern::operator=(Intern const & rhs)
{
	std::cout << "Intern Copy assignment operator called" << std::endl;
	(void) rhs;
	return (*this);
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	int	i = 0;
	std::string	forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	while (i < 3 && forms[i] != form)
		i++;
	switch (i)
	{
		case (0):
			std::cout << "Intern creates " << form << "." << std::endl;
			return (new PresidentialPardonForm(target));
		case (1):
			std::cout << "Intern creates " << form << "." << std::endl;
			return (new RobotomyRequestForm(target));
		case (2):
			std::cout << "Intern creates " << form << "." << std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			std::cout << "Intern can't create " << form << " as it is not a valid form." << std::endl;
			return (NULL);
	}
}
