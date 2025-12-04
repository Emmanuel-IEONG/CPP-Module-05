/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:44:18 by eieong            #+#    #+#             */
/*   Updated: 2025/12/04 14:50:12 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
	#define SHRUBBERYCREATIONFORM_HPP
	#include <iostream>
	#include "AForm.hpp"
	#include <fstream>

	class	ShrubberyCreationForm : public AForm
	{
		private:
			std::string	_target;
		public:
			ShrubberyCreationForm();
			ShrubberyCreationForm(ShrubberyCreationForm const & src);
			ShrubberyCreationForm(const std::string target);
			~ShrubberyCreationForm();
			ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & rhs);
			std::string		getTarget() const;
			virtual void	execute(Bureaucrat const & executor) const;
	};

#endif
