/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:45:45 by eieong            #+#    #+#             */
/*   Updated: 2025/12/09 11:40:38 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("NoName", 145, 137), _target("NoTarget")
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _target(src._target)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery creation", 145, 137), _target(target)
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
	if (this != &rhs)
	{
		this->setSignedStatus(rhs.getSignedStatus());
		this->_target = rhs._target;
	}
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!(this->getSignedStatus()))
		throw(AForm::FormNotSignedException());
	else if (executor.getGrade() > this->getGradeToExecute())
		throw(AForm::GradeTooLowException());
	else
	{
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		std::ofstream	outfile(this->getTarget().append("_shruberry").c_str());
		outfile << "       _-_" << std::endl;
		outfile << "    /~~   ~~\\" << std::endl;
		outfile << " /~~         ~~\\" << std::endl;
		outfile << "{               }" << std::endl;
		outfile << " \\  _-     -_  /" << std::endl;
		outfile << "   ~  \\\\ //  ~" << std::endl;
		outfile << "_- -   | | _- _" << std::endl;
		outfile << "  _ -  | |   -_" << std::endl;
		outfile << "      // \\\\" << std::endl;
		outfile.close();
	}
}
