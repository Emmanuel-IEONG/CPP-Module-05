/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:04:20 by eieong            #+#    #+#             */
/*   Updated: 2025/12/01 10:42:37 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int	main()
{
	std::cout << "<------------------Test constructor--------------------->" << std::endl;
	try
	{
		Bureaucrat	bro;
		std::cout << &bro;
		bro.incrementGrade();
		std::cout << &bro;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "<------------------Test constructor fail--------------------->" << std::endl;
	try
	{
		Bureaucrat	a("Failure", 160);
		std::cout << &a;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "<------------------Test constructor fail n2--------------------->" << std::endl;
	try
	{
		Bureaucrat	b("TooHigh", 0);
		std::cout << &b;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "<------------------Test incrementation fail--------------------->" << std::endl;
	try
	{
		Bureaucrat	c;
		std::cout << &c;
		c.decrementGrade();
		std::cout << &c;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "<------------------Test incrementation fail n2--------------------->" << std::endl;
	try
	{
		Bureaucrat	d("John", 2);
		std::cout << &d;
		d.decrementGrade();
		std::cout << &d;
		d.decrementGrade();
		std::cout << &d;
		d.decrementGrade();
		std::cout << &d;
		d.decrementGrade();
		std::cout << &d;
		d.decrementGrade();
		std::cout << &d;
		d.incrementGrade();
		std::cout << &d;
		d.incrementGrade();
		std::cout << &d;
		d.incrementGrade();
		std::cout << &d;
		d.incrementGrade();
		std::cout << &d;
		d.incrementGrade();
		std::cout << &d;
		d.incrementGrade();
		std::cout << &d;
		d.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
