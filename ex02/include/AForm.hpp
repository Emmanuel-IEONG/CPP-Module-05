/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 18:08:21 by eieong            #+#    #+#             */
/*   Updated: 2025/12/02 11:58:24 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
	#define AFORM_HPP
	#include <iostream>
	#include <string>
	#include "Bureaucrat.hpp"

	class	Bureaucrat;

	class	AForm
	{
		private:
			const std::string	_name;
			bool				_signed;
			const int			_sign_grade;
			const int			_execute_grade;
		public:
			AForm();
			AForm(AForm const & src);
			AForm(const std::string name, const int sign_grade, const int execute_grade);
			~AForm();
			AForm &	operator=(AForm const & rhs);
			const std::string	getName() const;
			bool	getSignedStatus() const;
			int	getGradeToSign() const;
			int	getGradeToExecute() const;
			void	beSigned(Bureaucrat &b);

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

	std::ostream	&operator<<(std::ostream &out, AForm *f);

#endif
