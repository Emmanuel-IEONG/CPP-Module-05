/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:05:09 by eieong            #+#    #+#             */
/*   Updated: 2025/11/28 12:26:23 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("NoName"), _grade(150)
{
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat Parametric constructor called" << std::endl;
	try
	{
		if (grade < 1)
			throw (GradeTooHighException());
		else if (grade > 150)
			throw (GradeTooLowException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const & rhs)
{
	std::cout << "Bureaucrat Copy assignment operator called" << std::endl;

	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	try
	{
		this->_grade--;
		if (this->getGrade() < 1)
			throw (GradeTooHighException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		this->_grade++;
		if (this->getGrade() > 1)
			throw (GradeTooLowException());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high (< 1)");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low (> 150)");
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat *b)
{
	out << b->getName() << ", bureaucrat grade " << b->getGrade() << "." << std::endl;
	return (out);
}

