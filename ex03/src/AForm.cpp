/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:08:17 by eieong            #+#    #+#             */
/*   Updated: 2025/12/09 11:39:07 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm() : _name("NoName"), _signed(false), _sign_grade(1), _execute_grade(1)
{
	std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(AForm const & src) : _name(src._name), _signed(false), _sign_grade(src._sign_grade), _execute_grade(src._execute_grade)
{
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int sign_grade, const int execute_grade) : _name(name), _signed(false), _sign_grade	(sign_grade), _execute_grade(execute_grade)
{
	std::cout << "AForm Parametric constructor called" << std::endl;
	if (sign_grade < 1 || execute_grade < 1)
		throw (GradeTooHighException());
	else if (sign_grade > 150 || execute_grade > 150)
		throw (GradeTooLowException());
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}

AForm &	AForm::operator=(AForm const & rhs)
{
	std::cout << "AForm Copy assignment operator called" << std::endl;

	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

const std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSignedStatus() const
{
	return (this->_signed);
}

int	AForm::getGradeToSign() const
{
	return (this->_sign_grade);
}

int	AForm::getGradeToExecute() const
{
	return (this->_execute_grade);
}

void	AForm::setSignedStatus(bool signedstatus)
{
	this->_signed = signedstatus;
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (this->getGradeToSign() < b.getGrade())
		throw(GradeTooLowException());
	else if (!(this->getSignedStatus()))
	{
		std::cout << "Bureaucrat " << b.getName() << " signed " << this->getName() << " form." << std::endl;
		this->_signed = true;
	}
	else
		std::cout << "Bureaucrat " << b.getName() << " couldn't sign " << this->getName() << " form because it was already signed." << std::endl;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

std::ostream	&operator<<(std::ostream &out, AForm *f)
{
	if (!f->getSignedStatus())
		out << f->getName() << ", not signed. Grade required to sign : " << f->getGradeToSign() << " and to execute : " << f->getGradeToExecute() << std::endl;
	else
		out << f->getName() << ", signed. Grade required to sign : " << f->getGradeToSign() << " and to execute : " << f->getGradeToExecute() << std::endl;
	return (out);
}
