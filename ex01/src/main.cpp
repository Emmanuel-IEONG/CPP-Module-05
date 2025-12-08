/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:08:19 by eieong            #+#    #+#             */
/*   Updated: 2025/12/08 14:56:00 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/color.hpp"

static void sep()
{
	std::cout << "-------------------------------------------------------" << std::endl;
}

int main()
{
	std::cout << BLUE "1) Test invalid Bureaucrat construction\n" RESET << std::endl;
	try
	{
		std::cout << YELLOW "a) Construction Bureaucrat with grade too high (0)..." RESET << std::endl;
		Bureaucrat b1("TooHigh", 0);
		(void)b1;
	}
	catch (std::exception &e)
	{
		std::cerr << " -> Exception: " << e.what() << std::endl;
	}
	sep();
	try
	{
		std::cout << YELLOW "b) Construction Bureaucrat with grade too low (151)..." RESET << std::endl;
		Bureaucrat b2("TooLow", 151);
		(void)b2;
	}
	catch (std::exception &e)
	{
		std::cerr << " -> Exception: " << e.what() << std::endl;
	}
	sep();
	std::cout << BLUE "2) Test increment/decrement\n" RESET << std::endl;
	try
	{
		std::cout << YELLOW "a) Increment until out of range (from 2 to 1 then 0)..." RESET << std::endl;
		Bureaucrat boss("Boss", 2);
		std::cout << &boss;
		boss.incrementGrade(); // 1
		std::cout << " after increment: " << &boss;
		boss.incrementGrade(); // throw
	}
	catch (std::exception &e)
	{
		std::cerr << " -> Exception: " << e.what() << std::endl;
	}
	sep();
	try
	{
		std::cout << YELLOW "b) Decrement until out of range (150 -> 151)..." RESET << std::endl;
		Bureaucrat intern("Intern", 149);
		std::cout << &intern;
		intern.decrementGrade(); // 150
		std::cout << " after decrement: " << &intern;
		intern.decrementGrade(); // throw
	}
	catch (std::exception &e)
	{
		std::cerr << " -> Exception: " << e.what() << std::endl;
	}
	sep();
	std::cout << BLUE "3) Test invalid Form construction\n" RESET << std::endl;
	try
	{
		std::cout << YELLOW "a) Construction Form with sign_grade too low (160)..." RESET << std::endl;
		Form f1("BadSign", 160, 10);
		(void)f1;
	}
	catch (std::exception &e)
	{
		std::cerr << " -> Exception: " << e.what() << std::endl;
	}
	sep();
	try
	{
		std::cout << YELLOW "b) Construction Form with exec_grade too high (0)..." RESET << std::endl;
		Form f2("BadExec", 10, 0);
		(void)f2;
	}
	catch (std::exception &e)
	{
		std::cerr << " -> Exception: " << e.what() << std::endl;
	}
	sep();
	std::cout << BLUE "4) Test beSigned and signForm (insufficient grade/ sufficient / double signature)\n" RESET << std::endl;
	Form contract("Contract", 50, 25);
	Bureaucrat junior("Junior", 100);
	Bureaucrat manager("Manager", 40);
	Bureaucrat director("Director", 1);

	std::cout << "Initial Form: " << &contract;
	std::cout << CYAN << &junior << LYELLOW << &manager << LRED << &director << RESET;
	sep();
	try
	{
		std::cout << YELLOW "a) Junior try to sign (grade 100)" RESET << std::endl;
		contract.beSigned(junior);
	}
	catch (std::exception &e)
	{
		std::cerr << " -> Exception on beSigned: " << e.what() << std::endl;
	}
	sep();

	try
	{
		std::cout << YELLOW "b) Manager sign via Bureaucrat::signForm (grade 40)" RESET << std::endl;
		manager.signForm(contract);
		std::cout << " after signing: " << &contract;
	}
	catch (std::exception &e)
	{
		std::cerr << " -> Unexpected exception: " << e.what() << std::endl;
	}
	sep();
	try
	{
		std::cout << YELLOW "c) Director try to sign again (already signed)" RESET << std::endl;
		director.signForm(contract);
	}
	catch (std::exception &e)
	{
		std::cerr << " -> Exception" << e.what() << std::endl;
	}
	sep();
	std::cout << BLUE "End of tests" RESET << std::endl;
	return 0;
}
