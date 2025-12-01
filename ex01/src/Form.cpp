/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:08:17 by eieong            #+#    #+#             */
/*   Updated: 2025/12/01 14:06:57 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form() : _name("NoName"), _signed(false), _grade_to_sign(1), _grade_to_execute(1)
{
	std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(Form const & src) : _name(src._name), _signed(false), _grade_to_sign(src._grade_to_sign), _grade_to_execute(src._grade_to_execute)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

Form::Form(const std::string name, const int grade_to_sign, const int grade_to_execute) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	std::cout << "Form Parametric constructor called" << std::endl;
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw (GradeTooHighException());
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw (GradeTooLowException());
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

Form &	Form::operator=(Form const & rhs)
{
	std::cout << "Form Copy assignment operator called" << std::endl;

	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

const std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSignedStatus() const
{
	return (this->_signed);
}

int	Form::getGradeToSign() const
{
	return (this->_grade_to_sign);
}

int	Form::getGradeToExecute() const
{
	return (this->_grade_to_execute);
}

void	Form::beSigned(Bureaucrat &b)
{
	if (this->getGradeToSign() < b.getGrade())
		throw(GradeTooLowException());
	else if (!(this->getSignedStatus()))
	{
		std::cout << "Bureaucrat " << b.getName() << " signed " << this->getName() << " form." << std::endl;
		this->_signed = true;
	}
	else
		std::cout << "Bureaucrat " << b.getName() << " couldn't sign " << this->getName() << " because it was already signed." << std::endl;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream	&operator<<(std::ostream &out, Form *f)
{
	if (!f->getSignedStatus())
		out << f->getName() << ", not signed. Grade required to sign : " << f->getGradeToSign() << " and to execute : " << f->getGradeToExecute() << std::endl;
	else
		out << f->getName() << ", signed. Grade required to sign : " << f->getGradeToSign() << " and to execute : " << f->getGradeToExecute() << std::endl;
	return (out);
}
