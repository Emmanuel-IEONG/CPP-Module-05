/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:47:01 by eieong            #+#    #+#             */
/*   Updated: 2025/12/04 15:53:12 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("NoName", 25, 5), _target("NoTarget")
{
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
{
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential pardon", 25, 5), _target(target)
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

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!(this->getSignedStatus()))
		throw(AForm::FormNotSignedException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw(AForm::GradeTooLowException());
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphor Beelbebrox." << std::endl;
}
