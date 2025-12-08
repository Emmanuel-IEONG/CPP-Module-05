/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:07:02 by eieong            #+#    #+#             */
/*   Updated: 2025/12/08 14:57:18 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/color.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Intern.hpp"

static void sep()
{
	std::cout << "-------------------------------------------------------" << std::endl;
}

int main()
{
	Intern		intern;
	Bureaucrat	noob("Noob", 150);
	Bureaucrat	junior("Junior", 138);
	Bureaucrat	manager("Manager", 40);
	Bureaucrat	director("Director", 1);
	AForm	*shrubb;
	AForm	*robotomy;
	AForm	*pardon;
	AForm	*invalid;
	shrubb = intern.makeForm("ShrubberyCreationForm", "home");
	robotomy = intern.makeForm("RobotomyRequestForm", junior.getName());
	pardon = intern.makeForm("PresidentialPardonForm", manager.getName());
	invalid = intern.makeForm("InvalidForm", "what");

	std::cout << "------------------------Reminder------------------------\n";
	std::cout << &noob;
	std::cout << &junior;
	std::cout << &manager;
	std::cout << &director << std::endl;
	std::cout << shrubb << "Target : " << shrubb->getTarget() << std::endl;
	std::cout << robotomy << "Target : " << robotomy->getTarget() << std::endl;
	std::cout << pardon  << "Target : " << pardon->getTarget() << std::endl;
	sep();
	std::cout << LBLUE "A) Grade boundary exceptions" RESET << std::endl;
	try {
		std::cout << YELLOW "-> Trying to decrement Noob (150) (should throw GradeTooLow)" RESET << std::endl;
		noob.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << " -> Exception: " << e.what() << std::endl;
	}
	try {
		std::cout << YELLOW "-> Trying to increment Director (1) (should throw GradeTooHigh)" RESET << std::endl;
		director.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << " -> Exception: " << e.what() << std::endl;
	}
	sep();
	std::cout << LBLUE "B) ShrubberyCreationForm tests (sign 145, exec 137)" RESET << std::endl;
	try {
		std::cout << YELLOW "-> Noob tries to sign Shrubbery (should fail)" RESET << std::endl;
		shrubb->beSigned(noob);
	} catch (std::exception &e) {
		std::cerr << " -> Exception (beSigned): " << e.what() << std::endl;
	}
	try {
		std::cout << YELLOW "-> Junior tries to sign Shrubbery (should succeed)" RESET << std::endl;
		shrubb->beSigned(junior);
		std::cout << " -> Signed successfully by Junior" << std::endl;
	} catch (std::exception &e) {
		std::cerr << " -> Exception (beSigned): " << e.what() << std::endl;
	}
	try {
		std::cout << YELLOW "-> Junior tries to execute Shrubbery (should fail: exec grade too low)" RESET << std::endl;
		junior.executeForm(*shrubb);
	} catch (std::exception &e) {
		std::cerr << " -> Exception (execute): " << e.what() << std::endl;
	}
	try {
		std::cout << YELLOW "-> Manager tries to sign Shrubbery (should fail: already signed)" RESET << std::endl;
		shrubb->beSigned(junior);
		std::cout << " -> Signed successfully by Junior" << std::endl;
	} catch (std::exception &e) {
		std::cerr << " -> Exception (beSigned): " << e.what() << std::endl;
	}
	try {
		std::cout << YELLOW "-> Manager tries to execute Shrubbery (should succeed)" RESET << std::endl;
		manager.executeForm(*shrubb);
	} catch (std::exception &e) {
		std::cerr << " -> Exception (execute): " << e.what() << std::endl;
	}
	sep();
	std::cout << LBLUE "C) RobotomyRequestForm tests (sign 72, exec 45)" RESET << std::endl;
	try {
		std::cout << YELLOW "-> Manager tries to execute unsigned Robotomy (should fail: not signed)" RESET << std::endl;
		manager.executeForm(*robotomy);
	} catch (std::exception &e) {
		std::cerr << " -> Exception (execute unsigned): " << e.what() << std::endl;
	}
	try {
		std::cout << YELLOW "-> Manager signs Robotomy (should succeed)" RESET << std::endl;
		robotomy->beSigned(manager);
		std::cout << " -> Robotomy signed by Manager" << std::endl;
	} catch (std::exception &e) {
		std::cerr << " -> Exception (beSigned): " << e.what() << std::endl;
	}
	std::cout << YELLOW "-> Manager executes Robotomy several times to show randomized result:" RESET << std::endl;
	for (int i = 0; i < 5; ++i) {
		try {
			manager.executeForm(*robotomy);
		} catch (std::exception &e) {
			std::cerr << " -> Exception (execute): " << e.what() << std::endl;
		}
	}
	sep();
	std::cout << LBLUE "D) PresidentialPardonForm tests (sign 25, exec 5)" RESET << std::endl;
	try {
		std::cout << YELLOW "-> Manager tries to sign Pardon (should fail)" RESET << std::endl;
		pardon->beSigned(manager);
	} catch (std::exception &e) {
		std::cerr << " -> Exception (beSigned): " << e.what() << std::endl;
	}
	try {
		std::cout << YELLOW "-> Director signs Pardon (should succeed)" RESET << std::endl;
		pardon->beSigned(director);
		std::cout << " -> Pardon signed by Director" << std::endl;
	} catch (std::exception &e) {
		std::cerr << " -> Exception (beSigned): " << e.what() << std::endl;
	}
	try {
		std::cout << YELLOW "-> Director executes Pardon (should succeed)" RESET << std::endl;
		director.executeForm(*pardon);
	} catch (std::exception &e) {
		std::cerr << " -> Exception (execute): " << e.what() << std::endl;
	}
	sep();
	std::cout << "Tests completed." << std::endl;
	delete (shrubb);
	delete (robotomy);
	delete (pardon);
	return (0);
}
