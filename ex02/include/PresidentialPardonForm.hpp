/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:46:41 by eieong            #+#    #+#             */
/*   Updated: 2025/12/04 14:46:48 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
	#define PRESIDENTIALPARDONFORM_HPP
	#include <iostream>
	#include "AForm.hpp"

	class	PresidentialPardonForm : public AForm
	{
		private:
			std::string	_target;
		public:
			PresidentialPardonForm();
			PresidentialPardonForm(PresidentialPardonForm const & src);
			PresidentialPardonForm(const std::string target);
			~PresidentialPardonForm();
			PresidentialPardonForm &	operator=(PresidentialPardonForm const & rhs);
			std::string		getTarget() const;
			virtual void	execute(Bureaucrat const & executor) const;
	};

#endif
