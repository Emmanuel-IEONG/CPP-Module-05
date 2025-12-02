/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:46:05 by eieong            #+#    #+#             */
/*   Updated: 2025/12/02 12:06:56 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
	#define ROBOTOMYREQUESTFORM_HPP
	#include <iostream>
	#include "AForm.hpp"

	class	RobotomyRequestForm : public AForm
	{
		public:
			RobotomyRequestForm();
			RobotomyRequestForm(RobotomyRequestForm const & src);
			RobotomyRequestForm(const std::string name);
			~RobotomyRequestForm();
			RobotomyRequestForm &	operator=(RobotomyRequestForm const & rhs);
	};

#endif
