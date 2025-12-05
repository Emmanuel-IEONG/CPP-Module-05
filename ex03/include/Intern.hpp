/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:38:22 by eieong            #+#    #+#             */
/*   Updated: 2025/12/05 11:47:08 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
	#define INTERN_HPP
	#include <iostream>
	#include "AForm.hpp"
	#include "PresidentialPardonForm.hpp"
	#include "RobotomyRequestForm.hpp"
	#include "ShrubberyCreationForm.hpp"

	class	Intern
	{
		public:
			Intern();
			Intern(Intern const & src);
			~Intern();
			Intern &	operator=(Intern const & rhs);
			AForm	*makeForm(std::string form, std::string target);
	};

#endif
