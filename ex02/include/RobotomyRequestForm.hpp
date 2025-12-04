/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:46:05 by eieong            #+#    #+#             */
/*   Updated: 2025/12/04 15:00:04 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
	#define ROBOTOMYREQUESTFORM_HPP
	#include <iostream>
	#include "AForm.hpp"
	#include <cstdlib>

	class	RobotomyRequestForm : public AForm
	{
		private:
			std::string	_target;
		public:
			RobotomyRequestForm();
			RobotomyRequestForm(RobotomyRequestForm const & src);
			RobotomyRequestForm(const std::string target);
			~RobotomyRequestForm();
			RobotomyRequestForm &	operator=(RobotomyRequestForm const & rhs);
			std::string		getTarget() const;
			virtual void	execute(Bureaucrat const & executor) const;
	};

#endif
