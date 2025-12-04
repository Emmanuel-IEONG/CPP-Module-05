/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:46:27 by eieong            #+#    #+#             */
/*   Updated: 2025/12/04 16:17:00 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("NoName", 72, 45), _target("NoTarget")
{
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src)
{
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy request", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Parametric constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
	(void) rhs;
	return (*this);
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	static int	r = 1;	//Resolve PRNG

	if (!(this->getSignedStatus()))
		throw(AForm::FormNotSignedException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw(AForm::GradeTooLowException());
	else
	{
		std::cout << "Dzzzzzz Dzzzzz Dzzz" << std::endl;
		srand(time(NULL));
		if ((rand() / r) % 2)	//PRNG...
			std::cout << this->getTarget() << " has been robotomized." << std::endl;
		else
			std::cout << "Robotomy failed on " << this->getTarget() << "." << std::endl;
		r++;
	}
}
