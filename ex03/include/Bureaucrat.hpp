/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:05:02 by eieong            #+#    #+#             */
/*   Updated: 2025/12/03 15:42:57 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
	#define BUREAUCRAT_HPP
	#include <iostream>
	#include <string>
	#include "AForm.hpp"

	class	AForm;

	class	Bureaucrat
	{
		private:
			const std::string	_name;
			int					_grade;

		public:
			Bureaucrat();
			Bureaucrat(const std::string, int grade);
			Bureaucrat(Bureaucrat const & src);
			~Bureaucrat();

			Bureaucrat	&operator=(Bureaucrat const & rhs);
			const std::string	getName() const;
			int			getGrade() const;
			void		incrementGrade();
			void		decrementGrade();
			void		signForm(AForm &f);
			void		executeForm(AForm const & form) const;
			
		class	GradeTooHighException : public std::exception
		{
			public:
			virtual const char *what() const throw();
		};
		
		class	GradeTooLowException : public std::exception
		{
			public:
			virtual const char *what() const throw();
		};
	};

	std::ostream	&operator<<(std::ostream &out, Bureaucrat *b);

#endif
