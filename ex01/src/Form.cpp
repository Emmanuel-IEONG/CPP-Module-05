/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:08:17 by eieong            #+#    #+#             */
/*   Updated: 2025/11/28 18:08:39 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form()
{
	std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(Form const & src)
{
	std::cout << "Form Copy constructor called" << std::endl;
	*this = src;
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

Form &	Form::operator=(Form const & rhs)
{
	std::cout << "Form Copy assignment operator called" << std::endl;

	if (this != &rhs)
	{
		/* attributes to copy */
	}

	return (*this);
}
