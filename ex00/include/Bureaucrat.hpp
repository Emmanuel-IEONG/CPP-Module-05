/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:05:02 by eieong            #+#    #+#             */
/*   Updated: 2025/11/21 14:12:23 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
	#define BUREAUCRAT_HPP
	#include <iostream>

	class	Bureaucrat
	{
		private:
			std::string	_name;
			int			_grade;

		public:
			Bureaucrat();
			Bureaucrat(Bureaucrat const & src);
			~Bureaucrat();

			Bureaucrat &	operator=(Bureaucrat const & rhs);
			std::string	getName() const;
			int	getGrade() const;
			void	increaseGrade();
			void	decreaseGrade();
	};

#endif
